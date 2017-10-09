#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.h"
#include "blinky.h"
#include "pinky.h"
#include "inky.h"

class       Blinky;
class       Pinky;
class       Inky;

class       Clyde : public Ghost
{
private:
    Blinky  *blinky;
    Pinky   *pinky;
    Inky    *inky;
    Q_OBJECT
public:
    void    ft_set_default();
    void    ft_calculate_point();
    void    ft_find_pacman();
    void    ft_set_friends(Blinky *bl, Pinky *pnc, Inky *ink);
    void    ft_find_path();
            Clyde(QGraphicsScene *sc, int **map, PacMan *pc);
public slots:
    void    ft_move_ghost();
};
#endif // CLYDE_H
