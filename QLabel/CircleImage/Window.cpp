#include <QHBoxLayout>
#include "Window.h"
#include "label.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto hLayout = new QHBoxLayout(this);
    hLayout->addWidget(new Label(this));
    hLayout->addWidget(new Label(this));

    this->setStyleSheet("background:black;");
}

Widget::~Widget()
{
}

