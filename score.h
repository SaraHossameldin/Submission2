#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Game;

class Score: public QGraphicsTextItem{
public:
     Game* game;

    Score(QGraphicsTextItem * parent=0);
    void increase();
    int getScore();

private:
    int score;

};


#endif // SCORE_H
