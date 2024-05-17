#include "Ball.h"
#include <QTimer>
#include <QBrush>
#include "Game.h"
#include "paddle.h"
#include "Block.h"
#include "Game.h"
#include "level.h"
#include "Bar.h"
#include <math.h>

extern Game* game;

static double d2r(double d) {
    return (d / 180.0) * ((double) M_PI);
}

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    QPixmap pixmap(":/Image/Ball.png");
    pixmap = pixmap.scaled(QSize(30, 30), Qt::KeepAspectRatio);
    setPixmap(pixmap);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    ///setBrush(brush);

    // move up right initially
    speed = 2;
    ceta = 45;

}

double Ball::getCenterX(){
    return x() + 30/2;
}

void Ball::calcualteSpeed(){
    while (ceta > 360)
        ceta -= 360;
    while (ceta < 0)
        ceta += 360;
    xVelocity = cos(d2r(this->ceta)) * this->speed;
    yVelocity = -sin(d2r(this->ceta)) * this->speed;
}








