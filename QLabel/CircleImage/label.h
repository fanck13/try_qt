#ifndef LABEL_H
#define LABEL_H

#include <QObject>
#include <QLabel>
#include <QPixmap>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget *parent = nullptr, bool antiliasing =true );

private:
    bool antiliasing;
    int radius;
    QPixmap* target;
};

#endif // LABEL_H
