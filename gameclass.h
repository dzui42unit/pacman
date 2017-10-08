#ifndef GAMECLASS_H
#define GAMECLASS_H

#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <QTimer>
#include <QObject>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "pacman.h"
#include "blinky.h"
#include "pinky.h"

class   GameLoop : public QGraphicsView
{
private:
    QGraphicsScene                          *scene;
    QGraphicsView                           *view;
    QGraphicsPixmapItem                     **map_pix;
    PacMan                                  *pacman;
    Blinky                                  *blinky;
    Pinky                                   *pinky;
    int                                     **map_int;
public:
                                            GameLoop(char *file_name);
    void                                    ft_write_line_map(int *map, std::string str);
    void                                    ft_roll_game();
    void                                    ft_create_map();
    int                                     ft_check_file_inp(std::string str);
};

#endif // GAMECLASS_H
