#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QWidget>
class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool gameover;
    int scorevalue;
    int health = 3;
    QGraphicsTextItem * score;
    QWidget * w;
    QGraphicsView * view;
public:
    player(QWidget *w, QGraphicsView* view);
    void decreaseHealth();
    int getHealth();
public slots:
    void keyPressEvent(QKeyEvent * event);
    void createEnemy();
    void systemUpdater();
};

#endif // PLAYER_H
