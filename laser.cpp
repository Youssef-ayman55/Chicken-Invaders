#include "laser.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "enemy.h"


Laser::Laser(){
    setPixmap(QPixmap(":/images/resources/bullet.png"));

    QTimer * timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}

void Laser:: move()
{

    QList<QGraphicsItem *> colliding_items =collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            //Sound
            QAudioOutput* bulletoutput = new QAudioOutput();
            bulletoutput->setVolume(50);
            QMediaPlayer* bulletsound = new QMediaPlayer();
            bulletsound->setAudioOutput(bulletoutput);
            bulletsound->setSource(QUrl("qrc:/sound/resources/chicken.mp3"));
            bulletsound->play();
            //End sound
            //Increase Score
            ptr_player->scorevalue += 1;
            return;
        }
    }

    // *******  Moving the bullets upward ********
    setPos(x(),y()-10);
    if(pos().y()+30<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
