#ifndef LASER_H
#define LASER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Laser: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Laser();

public slots:
    void move();
};

#endif // BULLET_H
