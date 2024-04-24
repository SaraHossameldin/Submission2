#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Block: public QGraphicsRectItem
{
public:
    // Constructor
    Block(QGraphicsItem* parent=NULL);

};

#endif // BLOCK_H
