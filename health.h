#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
#include <QMessageBox>


class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsTextItem * parent=0);
    void decrease();
    int gethealth();

private:
    int health;

};


#endif // HEALTH_H
