#include "mainwindow.h"
#include <QApplication>
#include "parkingassistancegui.h"
#include "fifofordistances.h"
#include "fifoforvolume.h"

int main(int argc, char *argv[])
{
    QApplication senzorApplication(argc, argv);
    ParkingAssistanceGUI gui;
    makeFIFOforDistances();
    makeFIFOforVolume();
    gui.show();
    gui.runSenzorsGUI();
    //closeFIFO();

    return senzorApplication.exec();
}
