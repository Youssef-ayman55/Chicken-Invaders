#include "player.h"
#include <QKeyEvent>
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
}
void player::setmain(MainWindow * wptr){
    w = wptr;
}
