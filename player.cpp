#include "laser.h"
#include "enemy.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include "player.h"




player::player(QGraphicsTextItem * score): score(score)
{
    if(score == 0){
        scorevalue = 0;
        score = new QGraphicsTextItem;
        score->setPlainText("Score: " + QString::number(scorevalue));
    }
    setPos(550, 700);
    score->setPos(0,0);
}
void player::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Left){
        if(x() > 0) setPos(x() - 10 , 700);
    }
    else if(event->key() == Qt::Key_Right){
        if(x() < 1100) setPos(x() + 10, 700);
    }
    if(event->key() == Qt::Key_Space){
        Laser * bullet = new Laser();
        bullet->setPos(x() + pixmap().width()/2 - bullet->pixmap().width()/2, y());
        scene()->addItem(bullet);
    }
}
void player::createEnemy()
{   Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

