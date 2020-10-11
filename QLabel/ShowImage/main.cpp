#include <QApplication>

#include "imageview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageView imageView;
    imageView.show();
    return a.exec();
}
