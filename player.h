#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include "mainwindow.h"
class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int scorevalue;
    QGraphicsTextItem * score;
    MainWindow * w;
public:
    player(QGraphicsTextItem *score = 0);
    void setmain(MainWindow * wptr);
public slots:
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
