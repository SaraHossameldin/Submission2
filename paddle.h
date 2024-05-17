#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Paddle: public QGraphicsRectItem{
public:
    Paddle(QGraphicsItem* parent=NULL);

    double getCenterX();
    void keyPressEvent(QKeyEvent * event);
    void update(int iDeltaTime);

    int m_iWidth;
    int m_iSuperTime;

};

#endif // PADDLE_H
