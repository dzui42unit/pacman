#ifndef PACMAN_H
#define PACMAN_H

#define WIDTH 608
#define HEIGHT 702
#define size_x 21
#define size_y 19

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "stats.h"

class   PacMan : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int                         i_pos;
    int                         j_pos;
    int                         direction;
    int                         **map_int;
    QGraphicsPixmapItem         **map_pix;
    QGraphicsScene              *scene;
    void                        ft_update_scene();
    int                         ft_check_move(int i_pos, int j_pos);
    int                         scared;
public:
            PacMan(int **map_int, QGraphicsPixmapItem **map_pix, QGraphicsScene *scene);
    void    keyPressEvent(QKeyEvent *event);
    int     ft_get_pacman_i(void);
    void    ft_set_defaut();
    int     ft_scared_state();
    void    ft_set_scared();
    int     ft_get_pacman_j(void);
public slots:
    void    ft_move();
};

#endif // PACMAN_H
