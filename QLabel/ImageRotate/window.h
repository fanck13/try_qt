#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QImage>
class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

public slots:
    void doVFlip(bool checked);
    void doHFlip(bool checked);
    void doClockWiseRotate(bool checked);
    void doAntiClockWiseRotate(bool checked);
private:
    QLabel* imageLabel;
    QImage srcImage;

};
#endif // WINDOW_H
