#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include "player.h"
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow * w = new MainWindow;
    w->show();
    QGraphicsView * view = new QGraphicsView;
    QGraphicsScene * scene = new QGraphicsScene;
    QPixmap * player_image = new QPixmap("C:/Users/youss/Downloads/Chicken_Invaders/Chicken-Invaders/resources/player.png");
    player * plane = new player;
    view->setFixedSize(1200,800);
    scene->setSceneRect(0,0,1200,800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    plane->setPixmap(*player_image);
    plane->setmain(w);
    scene->addItem(plane);
    plane->setPos(550,700);
    plane->setFlag(QGraphicsItem::ItemIsFocusable);
    plane->setFocus();
    w->setview(view);
    return a.exec();
}
