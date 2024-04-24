#include "Block.h"
#include <QBrush>

Block::Block(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // Each Block will be represented by a rectangle
    setRect(160,0,30,30);

    //create a QBrush
    QBrush brush;

    //format the blocks style
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);

    setBrush(brush);
}
