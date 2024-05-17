#include "Paddle.h"
#include <QBrush>
#include<QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QDebug>

Paddle::Paddle(QGraphicsItem *parent): QGraphicsRectItem(parent){
    m_iSuperTime = 0;
    m_iWidth = 100;
    setRect(600,550,m_iWidth,20);

    //create a QBrush
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
}

double Paddle::getCenterX(){
    int xPos = rect().x();
    return xPos+m_iWidth/2;
}


void Paddle::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left){
        if (x() > 0){
            setPos(x()-20,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if ( (m_iSuperTime == 0 && x() + m_iWidth < 400) ||
            (m_iSuperTime > 0 && x() + m_iWidth < 450))
            setPos(x()+20,y());
    }
    //qDebug() << "Paddle Position: " << rect().x() << "," << rect().y();
}

void Paddle::update(int iDeltaTime){
    m_iSuperTime -= iDeltaTime;
    if (m_iSuperTime < 0)
        m_iSuperTime = 0;
    if (m_iSuperTime > 0) {
        m_iWidth = 200;
    } else {
        m_iWidth = 100;
    }
    /*QPixmap pixmap1(":/Image/paddle.png");
    pixmap1 = pixmap1.scaledToWidth(m_iWidth);
    pixmap1 = pixmap1.scaledToHeight(50);
    this->setPixmap(pixmap1);
    this->setVisible(true);
    */
    setRect(x(), 550, m_iWidth, 20);
    setVisible(true);

    //create a QBrush
    //QBrush brush;
    //m_iSuperTime > 0 ? brush.setColor(Qt::red) : brush.setColor(Qt::gray);
    //brush.setStyle(Qt::SolidPattern);
    //setBrush(brush);
}
