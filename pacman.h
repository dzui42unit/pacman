#ifndef PACMAN_H
#define PACMAN_H

#define WIDTH 1280
#define HEIGHT 640
#define size_x 10
#define size_y 20

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class   PacMan : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int                         i_pos;
    int                         j_pos;
    int                         direction;
    int                         map_int[size_x][size_y];
    QGraphicsPixmapItem         map_pix[size_x][size_y];
    QGraphicsScene              *scene;
public:
            PacMan(QGraphicsScene *scene);
    void    keyPressEvent(QKeyEvent *event);
    int     ft_check_move(int i_pos, int j_pos);
    int     ft_get_pacman_i(void);
    int     ft_get_pacman_j(void);
    void    ft_create_map();
    void    ft_update_scene();
public slots:
    void    ft_move();
};

#endif // PACMAN_H
