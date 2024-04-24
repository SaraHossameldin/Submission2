#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "score.h"
#include "health.h"
#include "Button.h"

class Game: public QGraphicsView{

   Q_OBJECT
public:
    Game(QWidget* parent=NULL);
    Score * score;

    Health * health;


    void Row_of_Blocks(int n);
    void Block_Display();
    void GameOver();
    void displayGameOver(QString text);
 bool gameOver;
    QGraphicsScene* scene;

public slots:
    void start();
   void RestartGame();

private:
   void showPanel(int x, int y, int width, int height, QColor color, double opacity);
    Button* playAgain;
    Button* exit;

};

#endif // GAME_H
