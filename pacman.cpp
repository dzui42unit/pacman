#include "pacman.h"

void    PacMan::ft_update_scene()
{
    if (map_int[i_pos][j_pos] == 3)
    {
        map_int[i_pos][j_pos] = 0;
        scene->removeItem(&(map_pix[i_pos][j_pos]));
    }
    if (map_int[i_pos][j_pos] == 4)
    {
        scared = 1;
        map_int[i_pos][j_pos] = 0;
        scene->removeItem(&(map_pix[i_pos][j_pos]));
    }
}

int     PacMan::ft_scared_state()
{
    return (scared);
}

void    PacMan::ft_set_scared()
{
    scared = !scared;
}

PacMan::PacMan(int **map_i, QGraphicsPixmapItem **map_p, QGraphicsScene *sc)
{
    i_pos = 15;
    j_pos = 9;
    direction = 0;
    map_int = map_i;
    map_pix = map_p;
    scene = sc;
    scared = 0;
    this->setPixmap(QPixmap(":/pics/pacman_left.png"));
    this->setPos(j_pos * 32, i_pos * 32);
    scene->addItem(this);
}

void    PacMan::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
     {
        this->direction = 3;
        this->setPixmap(QPixmap(":/pics/pacman_left.png"));
     }
     if (event->key() == Qt::Key_Right)
     {
        this->direction = 4;
         this->setPixmap(QPixmap(":/pics/pacman_right.png"));
     }
     if (event->key() == Qt::Key_Down)
     {
        this->direction = 2;
        this->setPixmap(QPixmap(":/pics/pacman_down.png"));
     }
     if (event->key() == Qt::Key_Up)
     {
        this->direction = 1;
        this->setPixmap(QPixmap(":/pics/pacman_up.png"));
     }
}

void    PacMan::ft_move()
{
    ft_update_scene();
    if (direction == 1)
    {
        if (i_pos == 0)
        {
           if (ft_check_move(size_x - 1, j_pos))
               i_pos = size_x - 1;
        }
        else
            if (ft_check_move(i_pos - 1, j_pos))
                i_pos--;
    }
    if (direction == 2)
    {
        if (i_pos == size_x - 1)
        {
            if (ft_check_move(0, j_pos))
                i_pos = 0;
        }
        else
            if (ft_check_move(i_pos + 1, j_pos))
                i_pos++;
    }
    if (direction == 3)
    {
        if (j_pos == 0)
        {
            if (ft_check_move(i_pos, size_y - 1))
                j_pos = size_y - 1;
        }
        else
            if (ft_check_move(i_pos, j_pos - 1))
                j_pos--;
    }
    if (direction == 4)
    {
        if (j_pos == size_y - 1)
        {
            if (ft_check_move(i_pos, 0))
                j_pos = 0;
        }
        else
            if (ft_check_move(i_pos, j_pos + 1))
                j_pos++;
    }
    this->setPos(j_pos * 32, i_pos * 32);
}

int     PacMan::ft_get_pacman_i(void)
{
    return (i_pos);
}

int     PacMan::ft_get_pacman_j(void)
{
    return (j_pos);
}

int     PacMan::ft_check_move(int i_pos, int j_pos)
{
    if (map_int[i_pos][j_pos] == 1)
        return (0);
    return (1);
}

void    PacMan::ft_set_defaut()
{
    i_pos = 15;
    j_pos = 9;

    direction = 0;
    this->setPos(j_pos * 32, i_pos * 32);
}