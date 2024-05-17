#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsTextItem>

class Game;

class level : public QGraphicsTextItem
{
public:
    static char levels[5][4][20];

    Game* game;
    level(int x, QGraphicsTextItem *parent=0);
    int getmaxScore(int level);
    int getLvl();
    void lvlUp();
    int getLvlVal(int level);
    float getMult();

private:
    int lvl;
    //speed multiplier depending on level
    float speedMultiplier[5] ={1,1.1,1.2,1.3,1.4};


};

#endif // LEVEL_H
