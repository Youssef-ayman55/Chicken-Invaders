#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QApplication>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_game_clicked()
{
    hide();
    view = new QGraphicsView;
    scene = new QGraphicsScene;
    player_image = new QPixmap(":/images/resources/player.png");
    plane = new player;
    view->setFixedSize(1200,800);
    scene->setSceneRect(0,0,1200,800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    plane->setPixmap(*player_image);
    scene->addItem(plane);
    plane->setPos(550,700);
    plane->setFlag(QGraphicsItem::ItemIsFocusable);
    plane->setFocus();
    view->show();
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),plane,SLOT(createEnemy()));
    time->start(2000);
}

