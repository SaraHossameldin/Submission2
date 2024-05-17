#include "Score.h"
#include "Game.h"
#include "level.h"
#include <QFont>
#include <QDebug>
//extern Game* game;
Score::Score(QGraphicsTextItem *parent): QGraphicsTextItem(parent){
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));
}

void Score::increase(){

    /*if(game->gameOver) {
        return;
    }*/

    score++;
    setPlainText(QString("Score: ") + QString::number(score));
    /*if(score == game->lvl->getmaxScore(game->lvl->getLvl())){
        game->lvl->lvlUp();
        int level = game->lvl->getLvl();
        int val = game->lvl->getLvlVal(level);

        game->nextLevel();
    }*/

}

int Score::getScore(){
    return score;
}
