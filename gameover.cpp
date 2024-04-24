#include "gameover.h"

gameover::gameover(QWidget *parent) : QGraphicsView(parent) {
    // Create a scene
    scene = new QGraphicsScene();
    setScene(scene);

    // Create a "Replay" button
    replayButton = new QPushButton("Replay");
    scene->addWidget(replayButton);
    connect(replayButton, &QPushButton::clicked, this, &gameover::replay);

    // Create a "Quit" button
    quitButton = new QPushButton("Quit");
    scene->addWidget(quitButton);
    connect(quitButton, &QPushButton::clicked, this, &gameover::quit);
}

