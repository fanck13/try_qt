#include <QPainter>
#include <QPainterPath>
#include "label.h"

Label::Label(QWidget *parent, bool _antiliasing):QLabel(parent), antiliasing(_antiliasing), radius(100)
{
    this->setMaximumSize(200, 200);
    this->setMinimumSize(200, 200);

    this->target = new QPixmap(this->size()) ;
    this->target->fill(Qt::transparent);

    auto p = QPixmap("./Data/Images/head.jpg").scaled(200, 200, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    auto painter = new QPainter(this->target);

    if(this->antiliasing){
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setRenderHint(QPainter::HighQualityAntialiasing, true);
        painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
    }

    QPainterPath path;
    path.addRoundedRect(0, 0, this->width(), this->height(), this->radius, this->radius);
    painter->setClipPath(path);

    painter->drawPixmap(0, 0, p);

    this->setPixmap(*(this->target));
}
