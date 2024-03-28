#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int scorevalue;
    QGraphicsTextItem * score;
public:
    player(QGraphicsTextItem *score = 0);
public slots:
    void keyPressEvent(QKeyEvent * event);
    void createEnemy();
};

#endif // PLAYER_H
