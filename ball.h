#ifndef BALL_H
#define BALL_H
#include "paddle.h"

#include<QGraphicsPixmapItem>
#include <QGraphicsRectItem>



class Ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    double xVelocity;
    double yVelocity;
    double speed = 5;
    double ceta = 135;
    // constructors
    Ball(QGraphicsItem* parent=NULL);

    // public methods
    double getCenterX();

    void calcualteSpeed();


public slots:
    // public slots



private:
    Paddle * paddle;
    // private attributes



    // private methods


};

#endif // BALL_H
