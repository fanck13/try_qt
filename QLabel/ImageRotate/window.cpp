#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QPainter>
#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent), imageLabel(nullptr), srcImage("./Data/fg.png")
{
    auto vLayout = new QVBoxLayout(this);
    this->imageLabel = new QLabel(this);
    this->imageLabel->setAlignment(Qt::AlignCenter);

    vLayout->addWidget(this->imageLabel);
    auto clayout = new QHBoxLayout();
    vLayout->addItem(clayout);

    clayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    auto hflip = new QPushButton(QString("水平翻转"), this);
    clayout->addWidget(hflip);

    auto vflip = new QPushButton(QString("竖直翻转"), this);
    clayout->addWidget(vflip);

    auto doClockWise = new QPushButton(QString("clockwise"), this);
    clayout->addWidget(doClockWise);

    auto doAntiClockWise = new QPushButton(QString("anticlockwise"), this);
    clayout->addWidget(doAntiClockWise);

    clayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    this->imageLabel->setPixmap(QPixmap::fromImage(this->srcImage));

    connect(hflip, &QPushButton::clicked, this, &Window::doHFlip);
    connect(vflip, &QPushButton::clicked, this, &Window::doVFlip);
    connect(doClockWise, &QPushButton::clicked, this, &Window::doClockWiseRotate);
    connect(doAntiClockWise, &QPushButton::clicked, this, &Window::doAntiClockWiseRotate);
}

Window::~Window()
{
}

void Window::doVFlip(bool checked)
{
    Q_UNUSED(checked);
    this->srcImage = this->srcImage.mirrored(true, false);
    this->imageLabel->setPixmap(QPixmap::fromImage(this->srcImage));
}

void Window::doHFlip(bool checked)
{
    Q_UNUSED(checked);
    this->srcImage = this->srcImage.mirrored(false, true);
    this->imageLabel->setPixmap(QPixmap::fromImage(this->srcImage));
}
void Window::doClockWiseRotate(bool checked)
{
    Q_UNUSED(checked);
    QImage image(this->srcImage.size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter;
    painter.begin(&image);
    auto hw = this->srcImage.width() / 2;
    auto hh = this->srcImage.height() / 2;
    painter.translate(hw, hh);
    painter.rotate(45);
    painter.drawImage(-hw, -hh, this->srcImage);
    painter.end();
    this->srcImage = image;
    this->imageLabel->setPixmap(QPixmap::fromImage(this->srcImage));
}

void Window::doAntiClockWiseRotate(bool checked)
{
    Q_UNUSED(checked);
    QImage image(this->srcImage.size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter;
    painter.begin(&image);
    auto hw = this->srcImage.width() / 2;
    auto hh = this->srcImage.height() / 2;
    painter.translate(hw, hh);
    painter.rotate(-45);
    painter.drawImage(-hw, -hh, this->srcImage);
    painter.end();
    this->srcImage = image;
    this->imageLabel->setPixmap(QPixmap::fromImage(this->srcImage));
}

