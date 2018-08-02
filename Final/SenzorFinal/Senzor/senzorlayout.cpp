#include "senzorlayout.h"

/*
void SenzorLayout::addItem(QLayoutItem *item)
{
    this->list.append(item);
}

QSize SenzorLayout::sizeHint() const
{

}

QSize SenzorLayout::minimumSize() const
{

}

int SenzorLayout::count() const
{

}

QLayoutItem *SenzorLayout::itemAt(int) const
{

}

QLayoutItem *SenzorLayout::takeAt(int)
{

}

void SenzorLayout::setGeometry(const QRect &r)
{
    QLayout::setGeometry(r);

    if (list.size() == 0)
        return;

    int w = r.width() - (list.count() - 1) * spacing();
    int h = r.height() - (list.count() - 1) * spacing();
    int i = 0;
    while (i < list.size()) {
        QLayoutItem *o = list.at(i);
        QRect geom(r.x() + i * spacing(), r.y() + i * spacing(), w, h);
        o->setGeometry(geom);
        ++i;
    }
}
*/
