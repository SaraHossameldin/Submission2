#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Game;

class level;

class Score: public QGraphicsTextItem{
public:
    Game* game;
    level* lvl;

    Score(QGraphicsTextItem * parent=0);
    void increase();
    int getScore();

private:
    int score;
    int maxScore;


};


#endif // SCORE_H
