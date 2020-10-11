#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QResource>
#include <QMovie>
#include <QDir>
#include <QDebug>
#include "imageview.h"

ImageView::ImageView(QWidget *parent) : QWidget(parent)
{
    //use the following code to check the current path
    /*QDir dir;
    QString pathname = dir.currentPath();
    qDebug()<<pathname;*/

    this->resize(800, 600);
    auto hLayout = new QHBoxLayout(this);
    auto label1 = new QLabel(this);
    QPixmap pixmap1(QString("./Data/head.jpg"));
    label1->setPixmap(pixmap1);
    hLayout->addWidget(label1);

    auto label2 = new QLabel(this);
    QPixmap pixmap2(QString(":/images/head.jpg"));
    label2->setPixmap(pixmap2);
    hLayout->addWidget(label2);

    QResource::registerResource("./Data/res.rcc");
    auto label3 = new QLabel(this);
    QPixmap pixmap3(QString(":/myfile/Data/images/head.jpg"));
    label3->setPixmap(pixmap3);
    hLayout->addWidget(label3);

    auto movie = new QMovie(QString("./Data/loading.gif"));
    auto movieLabel = new QLabel(this);
    movieLabel->setMovie(movie);
    hLayout->addWidget(movieLabel);

    movie->start();
}
