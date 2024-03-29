#include "gameover.h"
#include "ui_gameover.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QApplication>
#include <QTimer>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QColor>

GameOver::GameOver(QWidget *parent, QString x)
    : QDialog(parent)
    , ui(new Ui::GameOver)
{
    ui->setupUi(this);
    ui->ScoreText->setText(x);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_TryAgain_clicked()
{
    hide();
    view = new QGraphicsView;
    scene = new QGraphicsScene;
    player_image = new QPixmap(":/images/resources/player.png");
    QGraphicsTextItem * healthLabel = new QGraphicsTextItem();
    healthLabel->setPlainText("Health: 3");
    healthLabel->setDefaultTextColor(QColor(255, 0, 0));

    plane = new player(this, view);
    plane->score = healthLabel;
    view->setFixedSize(1200,800);
    scene->setSceneRect(0,0,1200,800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    plane->setPixmap(*player_image);
    scene->addItem(plane);
    scene->addItem(healthLabel);
    plane->setPos(550,700);
    plane->setFlag(QGraphicsItem::ItemIsFocusable);
    plane->setFocus();
    view->show();
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),plane,SLOT(createEnemy()));
    time->start(2000);
}

