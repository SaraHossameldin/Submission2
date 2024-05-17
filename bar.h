#ifndef BAR_H
#define BAR_H
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QBrush>

class Bar : public QGraphicsRectItem {
public:
    Bar(QGraphicsItem *parent = nullptr);
};

#endif // BAR_H
