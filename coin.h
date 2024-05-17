#ifndef COIN_H
#define COIN_H

#include <QGraphicsTextItem>

class Coin: public QGraphicsTextItem {
public:
    Coin(QGraphicsTextItem * parent=0);
    void increase();
    void decrease(int iAmount);
    int getCount();

private:
    int m_iCoins;

};


#endif // COIN_H
