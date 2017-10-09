#ifndef INKY_H
#define INKY_H

#include "ghost.h"
#include "blinky.h"
#include "clyde.h"
#include "pinky.h"

class       Blinky;
class       Pinky;
class       Clyde;

class       Inky : public Ghost
{
private:
    Blinky  *blinky;
    Clyde   *clyde;
    Pinky   *pinky;
    Q_OBJECT
public:
    void    ft_set_default();
    void    ft_calculate_point();
    void    ft_find_pacman();
    void    ft_set_friends(Blinky *bl, Pinky *pnc, Clyde *cld);
    void    ft_find_path();
            Inky(QGraphicsScene *sc, int **map, PacMan *pc);
public slots:
    void    ft_move_ghost();
};

#endif // INKY_H
