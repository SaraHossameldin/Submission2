#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>

class gameover : public QGraphicsView {
    Q_OBJECT

public:
    explicit gameover(QWidget *parent = nullptr);

signals:
    void replay();
    void quit();
private:
    QGraphicsScene* scene;
    QPushButton* replayButton;
    QPushButton* quitButton;
};

#endif // GAMEOVER_H
