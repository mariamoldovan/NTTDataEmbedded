#include "parkingassistancegui.h"
#include "ui_mygui.h"

#include <QPainter>
#include <QColor>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <QStackedWidget>
#include <QtSvg>
#include <QPixmap>
#include <fifofordistances.h>
#include <fifoforvolume.h>

const uint8_t windowLayoutMargins=20;
ParkingAssistanceGUI::ParkingAssistanceGUI(QWidget *parent) :
    QWidget(parent),
    widgetsContainer(new Ui::ParkingAssistanceGUI)
{
    widgetsContainer->setupUi(this);
    initGUI();
}

ParkingAssistanceGUI::~ParkingAssistanceGUI()
{
    delete widgetsContainer;
}

void ParkingAssistanceGUI::updateSenzors(uint8_t senzorsDistances[], uint8_t  franaDeMana)
{
    for (uint8_t senzor_id=0; senzor_id<5; senzor_id++)
        senzorWidgetContainers[senzor_id]->updateSenzor(senzorsDistances[senzor_id], franaDeMana);
}


void ParkingAssistanceGUI::initGUI()
{
    this->setLayout(widgetsContainer->windowLayout);
    widgetsContainer->windowLayout->setContentsMargins(windowLayoutMargins,windowLayoutMargins,windowLayoutMargins,windowLayoutMargins);
    this->constructParkingAssistanceGUI();
    //QObject::connect(widgetsContainer->volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(sendVolume(int)));
    QObject::connect(widgetsContainer->volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(changeVolumeLabel(int)));
    QPixmap pixmap(":/Resources/VolumeImg/vol0.png");
    widgetsContainer->volumeImage->setPixmap(pixmap);
}

void ParkingAssistanceGUI::constructParkingAssistanceGUI()
{
    QStackedLayout* senzorsLayout = new QStackedLayout{};

    senzorsLayout->setStackingMode(QStackedLayout::StackAll);
    widgetsContainer->senzorWidget->setLayout(senzorsLayout);
    widgetsContainer->windowLayout->addWidget(widgetsContainer->senzorWidget);

    for (uint8_t senzorWidgetIterator=0; senzorWidgetIterator<NR_Senzors; senzorWidgetIterator++)
    {
        SenzorWidgetContainer* senzorWidgetContainer = new SenzorWidgetContainer{senzorWidgetIterator+1, Senzor_Range, NR_Segments};
        senzorWidgetContainers.push_back(senzorWidgetContainer);
        senzorWidgetContainers[senzorWidgetIterator]->drawSenzor();
        senzorsLayout->addWidget(senzorWidgetContainers[senzorWidgetIterator]->senzorFrame);

    }

    QSvgWidget* carWidget= new QSvgWidget{QString::fromStdString(":/Resources/SenzorSVG/car.svg")};
    senzorsLayout->addWidget(carWidget);

    QSvgWidget* frameWidget= new QSvgWidget{QString::fromStdString(":/Resources/SenzorSVG/frame.svg")};
    senzorsLayout->addWidget(frameWidget);
}


void ParkingAssistanceGUI::waitMillisecons(int miliSeconds)
{
    QTime dieTime= QTime::currentTime().addMSecs(miliSeconds);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void ParkingAssistanceGUI::changeHandBreak(uint8_t franaDeMana)
{
    if (franaDeMana==0)
    {
        QPixmap pixmap(":/Resources/BreakImg/breakoff.png");
        widgetsContainer->breakLabel->setPixmap(pixmap);
    }
    else
    {
        QPixmap pixmap(":/Resources/BreakImg/breakon.png");
        widgetsContainer->breakLabel->setPixmap(pixmap);

    }
}

void ParkingAssistanceGUI::changeVolumeLabel(int volume)
{
    int nrVolumeImage;
    if (volume==0)
        nrVolumeImage=0;
    else
        if (volume==99)
            nrVolumeImage=3;
        else
            nrVolumeImage=volume/33+1;
    QPixmap pixmap(":/Resources/VolumeImg/vol"+QString::number(nrVolumeImage)+".png");
    widgetsContainer->volumeImage->setPixmap(pixmap);
}

void ParkingAssistanceGUI::runSenzorsGUI()
{
    while (1)
    {
        uint8_t senzorsDistances[6];
        uint8_t  franaDeMana=0;
        getDistancesThroughFIFO(senzorsDistances, franaDeMana);
        sendVolume(widgetsContainer->volumeSlider->value());
        std::string str=std::to_string(senzorsDistances[0])+" "+std::to_string(senzorsDistances[1])+" "+std::to_string(senzorsDistances[2])+" "+std::to_string(senzorsDistances[3])+" "+std::to_string(senzorsDistances[4])+" "+std::to_string(franaDeMana);
        widgetsContainer->label->setText(QString::fromStdString(str));
        updateSenzors(senzorsDistances, franaDeMana);
        changeHandBreak(franaDeMana);
        //waitMillisecons(this->getGUI_RefreshRate());
        waitMillisecons(1);
    }

}

void ParkingAssistanceGUI::sendVolume(int volume)
{
    widgetsContainer->volumeValue->setText(QString::number(volume));
    sentVolumeThroughFIFO((uint8_t) volume);
}
