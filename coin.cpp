#include "coin.h"
#include "Game.h"
#include "level.h"
#include <QFont>
#include <QDebug>

Coin::Coin(QGraphicsTextItem *parent): QGraphicsTextItem(parent){
    m_iCoins = 0;
    setPlainText(QString("Coins: ") + QString::number(m_iCoins));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));
}

void Coin::increase(){
    m_iCoins++;
    setPlainText(QString("Coin: ") + QString::number(m_iCoins));
}

void Coin::decrease(int iAmount){
    m_iCoins -= iAmount;
    setPlainText(QString("Coin: ") + QString::number(m_iCoins));
}

int Coin::getCount(){
    return m_iCoins;
}
