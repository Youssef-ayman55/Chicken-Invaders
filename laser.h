#ifndef LASER_H
#define LASER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "player.h"
class Laser: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Laser();
    player* ptr_player;

public slots:
    void move();
};

#endif // BULLET_H
