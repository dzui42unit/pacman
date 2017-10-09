#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.h"
#include "pinky.h"
#include "clyde.h"
#include "inky.h"

class       Pinky;
class       Clyde;
class       Inky;

class       Blinky : public Ghost
{
private:
    Pinky           *pinky;
    Clyde           *clyde;
    Inky            *inky;
public:
                    Blinky(QGraphicsScene *sc, int **map, PacMan *pc);
    void            ft_set_default();
    void            ft_calculate_point();
    void            ft_find_pacman();
    void            ft_set_friends(Pinky *pin, Clyde *cl, Inky *ink);
    void            ft_find_path();
public slots:
    void            ft_move_ghost();
};

#endif // BLINKY_H
