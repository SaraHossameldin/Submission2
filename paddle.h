#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Paddle:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:


    double getCenterX();

    void keyPressEvent(QKeyEvent * event);

};

#endif // PADDLE_H
