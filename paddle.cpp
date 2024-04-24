#include "Paddle.h"
#include <QBrush>
#include<QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QDebug>



double Paddle::getCenterX(){
    return x()+50/2;
}


void Paddle::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0){
            setPos(x()-10,y());
        }


    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }}
