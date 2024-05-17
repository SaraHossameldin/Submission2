#include "Game.h"
#include "ball.h"
#include "Paddle.h"
#include "Block.h"
#include <QPixmap>
#include "Button.h"
#include <QTimer>
#include <QPushButton>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QFont>
#include "Bar.h"
#include"level.h"
#include "coin.h"
#include <cmath>

int levels_speed[5] = {15, 15, 10, 10, 5};
//int levels_speed[5] = {40,40,40,40,40};

Game::Game(QWidget *parent): QGraphicsView(parent){
    // initialize scene
    scene = new QGraphicsScene(0,0,800,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    gameOver=false;
    m_pBall = nullptr;
    m_pPaddle = nullptr;

    // qDebug() << "Game constructor: Signal-slot connections established.";
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBall()));
    timer->start(levels_speed[0]);
}

void Game::start(){

    gameOver = false;

    //Set the background
   /* QPixmap bgImage(":/Image/Background.jpg");
    background = new QGraphicsPixmapItem(bgImage);
    background->setPos(800, 60);
    scene->addItem(background);
    */

    // initialize the ball
    m_pBall = new Ball();
    m_pBall->setPos(200,500);
    scene->addItem(m_pBall);

    // create a paddle ;)
    Paddle* paddle = new Paddle();
    paddle->update(0);
    scene->addItem(paddle);
    paddle->setFlags(QGraphicsItem::ItemIsFocusable);
    paddle->setFocus();
    m_pPaddle = paddle;

    // Create the bar at the top of the scene
    Bar* topBar = new Bar();
    topBar->setPos(700,0);
    scene->addItem(topBar);

    // adding score
    m_pScore = new Score();
    m_pScore->setPos(700,70);
    m_pScore->game = this;
    scene->addItem(m_pScore);

    // adding coins
    m_pCoin = new Coin();
    m_pCoin->setPos(700,110);
    scene->addItem(m_pCoin);

    QPushButton* pButton = new QPushButton();
    pButton->setText("Power Up");
    pButton->setGeometry(700, 200, 100, 50);
    scene->addWidget(pButton);
    connect(pButton,SIGNAL(clicked()),this,SLOT(powerUp()));

    // adding health
    health = new Health();
    health->setPos(700,40);
    scene->addItem(health);

  // initialBlocks = x; // Store the initial number of blocks

    // Calculate level based on the number of blocks
    //To display Level
    lvl = new level(m_iLevel + 1);
    lvl->setPos(700,10);
    lvl->game = this;
    scene->addItem(lvl);

    // To show the blocks
    initializeBlocks();
}

void Game::initializeBlocks()
{
    //for testing of the collision
    //Block *block= new Block();
    //block->setRect(250, 470, 30, 30);
    //scene->addItem(block);

    //loop to initialize blocks
    for (int j=0;j < 20;j++)
    {
        for (int k=0;k<4;k++)
        {
            if (level::levels[m_iLevel][k][j] == 'B')
            {
                Block *block= new Block();
                block->setRect(j * 30, k * 30 + 45, 30, 30);
                scene->addItem(block);
            }
        }
    }
}

void Game::GameOver(bool lose)
{
    QString message;

    if(lose)
    {
        message = "Game Over. Your score is: " + QString::number(m_pScore->getScore());
        gameOver = true;
    }else if(!lose){
        message = "You Win!";
        gameOver = true;
    }

    displayGameOver(message);
}


void Game::displayGameOver(QString text)
{
    size_t n = scene->items().size();
    //disable the scene
    for(size_t i=0; i < n; i++)
    {
        scene->items()[i]->setEnabled(false);

    }


    // pop up semi transparent panel
    showPanel(0,0,1024,768,Qt::black,1);

    // draw panel
    showPanel(100,92,250,250,Qt::yellow, 1);

    //play again Button
    playAgain = new Button(QString("Play Again"));
    playAgain->setPos(120, 150);
    playAgain->setEnabled(true);
    playAgain->setFocus();
    scene->addItem(playAgain);
    connect(playAgain, SIGNAL(clicked()), this, SLOT(RestartGame()));

    //exit button
    exit = new Button(QString("Exit Game"));
    exit->setPos(120, 250);
    scene->addItem(exit);
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));


    //displaying the text
    QGraphicsTextItem* displayText = new QGraphicsTextItem(text);
    displayText->setPos(120,100);
    QGraphicsTextItem* displayLevel = new QGraphicsTextItem("Level: " + QString::number(lvl->getLvl()));
    displayLevel->setPos(120,120);
    QFont font;
    font.setPointSize(12);  // font size
    font.setBold(true);
    displayText->setFont(font);
    scene->addItem(displayText);
    displayLevel->setFont(font);
    scene->addItem(displayLevel);



}

void Game::RestartGame()
{
    qDebug() << "restartGame() slot called.";
    disconnect(this->playAgain, SIGNAL(clicked()), this, SLOT(RestartGame()));
    disconnect(this->exit, SIGNAL(clicked()), this, SLOT(close()));

    while(scene->items().count() > 0)
    {
        QGraphicsItem* item = scene->items().at(0);
        scene->removeItem(item);
        delete item;
    }

    // Clear scene
    // scene->clear();

    // Restart the game
    start();


}

void Game::nextLevel()
{
    while(scene->items().count() > 0)
    {
        QGraphicsItem* item = scene->items().at(0);
        scene->removeItem(item);
        delete item;
    }
    m_iLevel++;
    if (m_iLevel == 5) {
        QMessageBox::information(nullptr, "Well Done", "You have finished all the levels");
        close();
    } else {
        QMessageBox::information(nullptr, "Well Done", "You have finished this level");
    }
    m_iLevel = m_iLevel % 5;

    timer->stop();
    timer->start(levels_speed[m_iLevel]);

    // To move to the next level
    start();
}

void Game::showPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}
void Game::handleBlockCollision()
{
    QList<QGraphicsItem*> cItems = m_pBall->collidingItems();
    double delta_ceta = 0;

    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Block* block = dynamic_cast<Block*>(cItems[i]);
        // collides with block
        if (block){
            //new code
            double ballx = m_pBall->mapToScene(m_pBall->boundingRect()).boundingRect().center().x();
            double bally = m_pBall->mapToScene(m_pBall->boundingRect()).boundingRect().center().y();
            double blockx = block->mapToScene(block->boundingRect()).boundingRect().center().x();
            double blocky = block->mapToScene(block->boundingRect()).boundingRect().center().y();

            double yPad = block->mapToScene(block->boundingRect()).boundingRect().height();
            double xPad = block->mapToScene(block->boundingRect()).boundingRect().width();

            double delta_x = -blockx + ballx;
            double delta_y = -blocky + bally;

            double angle_radians = std::atan2(delta_y, delta_x);
            double angle_degrees = angle_radians * 180.0 / M_PI;
            while (angle_degrees < 0) angle_degrees += 360;
            // collides from top
            if (angle_degrees > 225 && angle_degrees < 315){
                if (m_pBall->ceta > 270)
                    m_pBall->ceta += 90;
                else
                    m_pBall->ceta -= 90;
            }
            // collides from left
            else if (angle_degrees < 45 || angle_degrees >= 315){
                if (m_pBall->ceta > 180)
                    delta_ceta = 90;
                else
                    delta_ceta = -90;
            }
            // collides from right
            else if (angle_degrees > 135 && angle_degrees < 225){
                if (m_pBall->ceta > 270)
                    delta_ceta = -90;
                else
                    delta_ceta = 90;
            }
            // collides from bottom
            else {
                if (m_pBall->ceta < 90)
                    delta_ceta = -90;
                else
                    delta_ceta = 90;
            }

            // delete block(s)
            this->scene->removeItem(block);
            this->m_pScore->increase();
            if (this->m_pScore->getScore() % 2 == 0)
                this->m_pCoin->increase();

            delete block;
        }
    }
    m_pBall->ceta += delta_ceta;
}

bool Game::checkWin()
{
    //uncomment this line to skip to required level
    //if (m_iLevel < 4) return true;

    for (int i = 0; i < this->scene->items().size(); i++){
        Block* block = dynamic_cast<Block*>(this->scene->items()[i]);
        if (block)
            return false;
    }
    return true;
}

void Game::handleBarCollision() {
    QList<QGraphicsItem*> cItems = m_pBall->collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Bar* bar = dynamic_cast<Bar*>(cItems[i]);
        if (bar){
            if (m_pBall->ceta > 270)
                m_pBall->ceta -= 90;
            else
                m_pBall->ceta += 90;
            return;
        }
    }
}
void Game::handlePaddleCollision(){
    QList<QGraphicsItem*> cItems = m_pBall->collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if (paddle){
            // collides with paddle
            // add to x velocity depending on where it hits the paddle
            QPolygonF ballRect = m_pBall->mapToScene(m_pBall->boundingRect());
            QPolygonF paddleRect = paddle->mapToScene(paddle->boundingRect());
            double ballCenter = ballRect.boundingRect().x() + 0.5 * ballRect.boundingRect().width();
            double paddleCenter = paddleRect.boundingRect().x() + 0.5 * paddleRect.boundingRect().width();

            //if (ballCenter > paddleCenter )
            //    m_pBall->ceta = 90;
            //else
            //    m_pBall->ceta -= 90;
            if (m_pBall->ceta > 270)
                m_pBall->ceta += 90;
            else
                m_pBall->ceta -= 90;

            return;
        }
    }
}
void Game::moveBall()
{
    if (m_pBall->pos().y() > 550)
    {
        health->decrease();
        m_pBall->setPos(200, 450);
        m_pBall->ceta = 45;
    }

    // if out of bounds, reverse the velocity
    reverseVelocityIfOutOfBounds();

    // if collides with paddle, reverse yVelocity, and add xVelocity
    // depending on where (in the x axis) the ball hits the paddle
    handlePaddleCollision();

    // handle collisions with blocks (destroy blocks and reverse ball velocity)
    handleBlockCollision();

    // if collides with bar, reverse yVelocity
    handleBarCollision();

    m_pBall->calcualteSpeed();

    //velocity is multiplied by the speed multiplier
    m_pBall->moveBy(m_pBall->xVelocity, m_pBall->yVelocity);

    if (checkWin())
    {
        nextLevel();
    }

    m_pPaddle->update(40);
    scene->update(0,0,700,700);//TODO
}
void Game::reverseVelocityIfOutOfBounds(){
    // check if out of bound, if so, reverse the proper velocity
    double screenW = width();


    // left edge
    if (m_pBall->mapToScene(m_pBall->boundingRect().topLeft()).x() <= 0){
        if (m_pBall->ceta > 180)
            m_pBall->ceta += 90;
        else
            m_pBall->ceta -= 90;
    }

    // right edge
    if (m_pBall->mapToScene(m_pBall->boundingRect().topRight()).x() >= screenW){
        m_pBall->ceta -= 90;
    }

    // top edge
    if (m_pBall->mapToScene(m_pBall->boundingRect().topLeft()).y() <= 0){
        if (m_pBall->ceta < 90)
            m_pBall->ceta -= 90;
        else
            m_pBall->ceta += 90;
    }

    // bottom edge - NONE (can fall through bottom)
}

void Game::powerUp() {
    if (m_pCoin->getCount() < 2){
        timer->stop();
        QMessageBox::information(nullptr, "Broke", "Please collect at least 2 coins");
        timer->start();
    } else {
        m_pPaddle->m_iSuperTime += 30000;
        m_pCoin->decrease(2);
    }
    m_pPaddle->setFocus();
}
