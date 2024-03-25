#ifndef GLOBAL_H
#define GLOBAL_H
#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include "player.h"
MainWindow * w = nullptr;
QGraphicsView * view = nullptr;
QGraphicsScene * scene = nullptr;
QPixmap * player_image = nullptr;
player * plane = nullptr;
#endif // GLOBAL_H
