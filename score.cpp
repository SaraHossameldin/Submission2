#include "Score.h"
#include "Game.h"
#include <QFont>

Score::Score(QGraphicsTextItem *parent): QGraphicsTextItem(parent){
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));
}

void Score::increase(){

    if(game->gameOver) {
        return;
    }

    score++;
    setPlainText(QString("Score: ") + QString::number(score));


}

int Score::getScore(){
    return score;
}
