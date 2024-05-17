#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>
#include "score.h"
#include "health.h"
#include "Button.h"
#include "level.h"
#include "ball.h"
#include "paddle.h"
#include "coin.h"

class Game: public QGraphicsView{

    Q_OBJECT
    QGraphicsPixmapItem *background;
public:
    Game(QWidget* parent=NULL);
    int m_iLevel = 0;
    Score * m_pScore;
    Coin * m_pCoin;
    Health * health;
    level * lvl;
    Ball* m_pBall;
    Paddle* m_pPaddle;

    //int lvlVal[5] = {4,6,8,10,12};
    //void nextLevel();
    void initializeBlocks();
    void GameOver(bool lose);
    void displayGameOver(QString text);
    bool gameOver;
    QGraphicsScene* scene;
    void handleBlockCollision();
    void handleBarCollision();
    void handlePaddleCollision();
    void reverseVelocityIfOutOfBounds();

    bool checkWin();

public slots:
    void start();
    void RestartGame();
    void nextLevel();
    void moveBall();
    void powerUp();

private:
    void showPanel(int x, int y, int width, int height, QColor color, double opacity);
    Button* playAgain;
    Button* exit;
    QTimer* timer;

};

#endif // GAME_H
