#include "Game.h"
#include "ball.h"
#include "Paddle.h"
#include "Block.h"
#include <QPixmap>
#include "Button.h"
#include <QGraphicsItem>


Game::Game(QWidget *parent): QGraphicsView(parent){
    // initialize scene
    scene = new QGraphicsScene(0,0,800,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    gameOver=false;

   // qDebug() << "Game constructor: Signal-slot connections established.";
}

void Game::start(){

    gameOver = false;

    // create a ball
    Ball* ball = new Ball();
    ball->setPos(390,500);
    scene->addItem(ball);

    // create a paddle ;)
    Paddle* paddle = new Paddle();
    QPixmap pixmap1("C:/Users/MARIANA/OneDrive - aucegypt.edu/Documents/BreakOutGame2-main/BreakOutGame2-main/paddle.png");
    pixmap1 = pixmap1.scaledToWidth(50);
    pixmap1 = pixmap1.scaledToHeight(50);
    paddle->setPixmap(pixmap1);
    paddle->setPos(350,550);
    scene->addItem(paddle);
    paddle->setFlags(QGraphicsItem::ItemIsFocusable);
    paddle->setFocus();

    // adding score
    score = new Score();
    score->setPos(700,0);
    score->game = this;
    scene->addItem(score);

    // adding health
    health = new Health();
    health->setPos(700,30);
    scene->addItem(health);



    // To show the blocks
    Block_Display();
}

void Game::Block_Display()
{
    int num=0;

    //to form 8 rows each containing 15 blocks
    for (int i = 0; i < 8; i++)
    {
        for (int j=0; j<15;j++)
        {
            Block * block= new Block();

            //since the y value is the same for the blocks in the same row
            // and each block has a width of 30.
            block->setPos(j*32,num);
            scene->addItem(block);
        }

        //since the height of each block is 30
        //and we want the block in the next row to be exactly under it.
        num+=30;
    }
}

void Game::GameOver()
{
    QString message;

    if(health->gethealth() <= 0)
    {
        message = "Game Over. Your score is: " + QString::number(score->getScore());
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
    showPanel(0,0,1024,768,Qt::black,0.65);

    // draw panel
    showPanel(312,184,400,400,Qt::lightGray,0.75);

    //play again Button
    playAgain = new Button(QString("Play Again"));
    playAgain->setPos(410, 330);
    playAgain->setEnabled(true);
    playAgain->setFocus();
    scene->addItem(playAgain);
    connect(playAgain, SIGNAL(clicked()), this, SLOT(RestartGame()));

    //exit button
   exit = new Button(QString("Exit Game"));
    exit->setPos(410, 400);
    scene->addItem(exit);
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));


    //displaying the text
    QGraphicsTextItem* displayText = new QGraphicsTextItem(text);
    displayText->setPos(410,225);
    QFont font;
    font.setPointSize(12);  // font size
    font.setBold(true);
    displayText->setFont(font);
    scene->addItem(displayText);
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



