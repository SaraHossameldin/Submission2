#include <QApplication>
#include "Game.h"
#include <QMessageBox>

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMessageBox::information(nullptr, "Game Start", "Press OK to start the game.");

    game = new Game();
    game->show();
    game->start();

    return a.exec();
}
