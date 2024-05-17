#include "Bar.h"
#include "QGraphicsItem.h"
Bar::Bar(QGraphicsItem *parent) : QGraphicsRectItem(parent) {
    setRect(0, 0, 100, 600); // Adjust size as needed
    setBrush(QBrush(Qt::gray)); // Set color as needed
}
