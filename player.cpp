#include "laser.h"
#include "enemy.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"



player::player(QWidget * w, QGraphicsView * view): w(w), view(view)
{
        scorevalue = 0;
        score = new QGraphicsTextItem;
        score->setPlainText("Score: " + QString::number(scorevalue));
    setPos(550, 700);
    score->setPos(0,0);

    QTimer * timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (systemUpdater()));
    timer->start(50);

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

void player::decreaseHealth(){
    if(health > 0)
        health--;
}

int player::getHealth(){return health;}

void player::systemUpdater(){
    QList<QGraphicsItem *> colliding_items =collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            if(health == 0){
                w->show();
                delete view;
                delete this;
            }

            delete colliding_items[i];

            decreaseHealth();
            return;
        }
    }

}

