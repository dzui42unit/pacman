#ifndef PINKY_H
#define PINKY_H

#include <QGraphicsPixmapItem>
#include "pacman.h"

class   Pinky : public QObject, public QGraphicsPixmapItem
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
    int             counter;
    QGraphicsScene  *scene;
public:
    void            ft_clear_map();
    void            ft_restore_path();
    int             ft_set_direction_near();
    void            ft_set_direction();
    void            ft_find_pacman();
    void            ft_set_default();
    void            ft_find_path();
    void            ft_calculate_point();
    int             ft_check_intersect();
    int             ft_check_move(int i_pos, int j_pos);
                    Pinky(QGraphicsScene *sc, int **map, PacMan *pc);
public slots:
    void            ft_move_ghost();
};

#endif // PINKY_H
