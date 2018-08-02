#ifndef SENZOR_H
#define SENZOR_H

#include <vector>
#include <QPainter>
#include <QLabel>
#include <QStackedLayout>
#include <QtSvg>

class SenzorWidgetContainer
{
private:
    uint8_t ID;
    uint8_t DIST_MAX=150;
    uint8_t NR_SEGM=5;
    uint8_t DIST_ACTUALA;


public:
    QWidget * senzorFrame;
    QStackedLayout * senzorLayout;
    std::vector<QSvgWidget*> segmentWidgets;

    SenzorWidgetContainer();
    SenzorWidgetContainer(const uint8_t ID, const uint8_t DIST_MAX, const uint8_t NR_SEGM);

    uint8_t getID() const { return ID; }

    uint8_t getNR_SEGM() const { return NR_SEGM; }
    void setNR_SEGM(const uint8_t NR_SEGM);

    uint8_t getDIST_MAX() const { return DIST_MAX; }
    void setDIST_MAX(const uint8_t DIST_MAX);

    uint8_t getDIST_ACTUALA() const { return DIST_ACTUALA; }
    void setDIST_ACTUALA(const uint8_t DIST_ACTUALA);

    void updateSenzor(const uint8_t DIST_ACTUALA, const uint8_t  franaDeMana);

    void drawSenzor();


};

#endif // SENZOR_H
