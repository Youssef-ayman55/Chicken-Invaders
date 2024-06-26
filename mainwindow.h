#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setview(QGraphicsView * viewptr);

private slots:
    void on_new_game_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsView * view;
    QGraphicsScene * scene;
    QPixmap * player_image;
    player * plane;
};
#endif // MAINWINDOW_H
