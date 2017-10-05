#ifndef GAMECLASS_H
#define GAMECLASS_H

#include <ctime>
#include <random>
#include <vector>
#include <iomanip>
#include <iostream>
#include <QTimer>
#include <QObject>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "pacman.h"

class   GameLoop : public QGraphicsView
{
private:
    QGraphicsScene              *scene;
    QGraphicsView               *view;
    int                         map_int[size_x][size_y];
    QGraphicsPixmapItem         map_pix[size_x][size_y];
    PacMan                      *pacman;
    int                         score;
    int                         lives;
public:
            GameLoop();
    void    ft_roll_game();
};

#endif // GAMECLASS_H
