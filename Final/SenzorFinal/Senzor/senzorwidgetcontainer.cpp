#include "senzorwidgetcontainer.h"
#include "senzorlayout.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
SenzorWidgetContainer::SenzorWidgetContainer()
{

}

SenzorWidgetContainer::SenzorWidgetContainer(const uint8_t ID, const uint8_t DIST_MAX, const uint8_t NR_SEGM)
{
    this->ID=ID;
    this->DIST_MAX= DIST_MAX;
    this->NR_SEGM= NR_SEGM;
}

void SenzorWidgetContainer::setNR_SEGM(const uint8_t NR_SEGM)
{
    this->NR_SEGM=NR_SEGM;
}

void SenzorWidgetContainer::setDIST_MAX(const uint8_t DIST_MAX)
{
    this->DIST_MAX=DIST_MAX;
}

void SenzorWidgetContainer::setDIST_ACTUALA(const uint8_t DIST_ACTUALA)
{
    this->DIST_ACTUALA=DIST_ACTUALA;
}

void SenzorWidgetContainer::updateSenzor(const uint8_t DIST_ACTUALA, const uint8_t  franaDeMana)
{
    setDIST_ACTUALA(DIST_ACTUALA);
    uint8_t nrSegment;
    if (DIST_ACTUALA<0 || DIST_ACTUALA>=150)
        nrSegment=0;
    else
        if (franaDeMana)
            nrSegment= this->getDIST_ACTUALA()/30+6;
        else
            nrSegment= this->getDIST_ACTUALA()/30+1;
    senzorLayout->setCurrentIndex(nrSegment);
}

void SenzorWidgetContainer::drawSenzor()
{
    this->senzorFrame = new QWidget{};
    this->senzorLayout = new QStackedLayout{};
    this->senzorFrame->setLayout(this->senzorLayout);

    QSvgWidget* emptySegmentWidget= new QSvgWidget{":/Resources/SenzorSVG/empty.svg"};
    this->segmentWidgets.push_back(emptySegmentWidget);
    this->senzorLayout->addWidget(this->segmentWidgets[0]);

   for (uint8_t coloredSegmentWidgetsIterator=1; coloredSegmentWidgetsIterator<=this->getNR_SEGM(); coloredSegmentWidgetsIterator++)
   {
       QSvgWidget* coloredSegmentWidget= new QSvgWidget{QString::fromStdString(":/Resources/SenzorSVG/s"+std::to_string(this->getID()) + std::to_string(coloredSegmentWidgetsIterator)+ ".svg")};
       this->segmentWidgets.push_back(coloredSegmentWidget);
       this->senzorLayout->addWidget(this->segmentWidgets[coloredSegmentWidgetsIterator]);
   }
   for (uint8_t greySegmentWidgetIterator=1; greySegmentWidgetIterator<=this->getNR_SEGM(); greySegmentWidgetIterator++)
   {
       QSvgWidget* greySegmentWidget= new QSvgWidget{QString::fromStdString(":/Resources/SenzorSVG/fs"+std::to_string(this->getID()) + std::to_string(greySegmentWidgetIterator)+ ".svg")};
       this->segmentWidgets.push_back(greySegmentWidget);
       this->senzorLayout->addWidget(this->segmentWidgets[greySegmentWidgetIterator+5]);
   }
}
