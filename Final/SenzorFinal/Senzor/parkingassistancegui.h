#ifndef MYGUI_H
#define MYGUI_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <vector>
#include "senzorwidgetcontainer.h"

#include <QHBoxLayout>
const uint8_t NR_Senzors=5;
const uint8_t NR_Segments=5; //number of segments per senzor
const uint8_t Senzor_Range=150; //maximum distance in cm sensed by a senzor

namespace Ui {
class ParkingAssistanceGUI;
}

class ParkingAssistanceGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ParkingAssistanceGUI(QWidget *parent = 0);
    ~ParkingAssistanceGUI();

private:
    Ui::ParkingAssistanceGUI *widgetsContainer;
    uint8_t GUI_RefreshRate=200; // time interval in miliseconds between GUI update

    std::vector<SenzorWidgetContainer*> senzorWidgetContainers;

    uint8_t getGUI_RefreshRate() const { return GUI_RefreshRate; }
    void setGUI_RefreshRate(const uint8_t GUI_RefreshRate);

    void updateSenzors(uint8_t senzorsDistances[], uint8_t  franaDeMana);
    void initGUI();
    void constructParkingAssistanceGUI();
    void waitMillisecons(int miliSeconds);
    void changeHandBreak(uint8_t franaDeMana);

public:
    void runSenzorsGUI();

public slots:
    void sendVolume(int volume);
    void changeVolumeLabel(int volume);
};

#endif // MYGUI_H
