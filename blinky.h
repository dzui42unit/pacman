#ifndef BLINKY_H
#define BLINKY_H

#include <QGraphicsPixmapItem>
#include "pacman.h"

class   Blinky : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int             i_pos;
    int             j_pos;
    int             direction;
    int             map_path[size_x][size_y];
    int             i_x;
    int             i_y;
    int             d;
    int             flag;
    int             i_exit;
    int             j_exit;
    int             x_dir[4] = { 1, -1, 0, 0 };
    int             y_dir[4] = { 0, 0, 1, -1 };
    PacMan          *pacman;
    QGraphicsScene  *scene;
public:
    void            ft_clear_map();
    void            ft_restore_path();
    int             ft_set_direction_near();
    void            ft_set_direction();
    void            ft_find_pacman();
                    Blinky(QGraphicsScene *sc, int **map, PacMan *pc);
public slots:
    void    ft_move_ghost();
};

#endif // BLINKY_H
