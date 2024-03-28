#include "laser.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>


Laser::Laser(){
    setPixmap(QPixmap(":/images/resources/bullet.png"));

    QTimer * timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}

void Laser:: move()
{



    // *******  Moving the bullets upward ********
    setPos(x(),y()-10);
    if(pos().y()+30<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
