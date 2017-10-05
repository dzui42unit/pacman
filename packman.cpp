#include <pacman.h>
#include <QGraphicsScene>

void    PacMan::ft_create_map()
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (i == 0 || j == 0
                    || i == size_x - 1 || j == size_y - 1)
                map_int[i][j] = 1;
            else
                map_int[i][j] = -1;
        }
    }
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (map_int[i][j] == 1)
            {
                map_pix[i][j].setPixmap(QPixmap(":/pics/greystone.png"));
                map_pix[i][j].setPos(j * 64, i * 64);
                scene->addItem(&(map_pix[i][j]));
            }
            else
            {
                map_pix[i][j].setPixmap(QPixmap(":/pics/ball.png"));
                map_pix[i][j].setPos(j * 64, i * 64);
                scene->addItem(&(map_pix[i][j]));
            }
        }
    }
}

void    PacMan::ft_update_scene()
{
    if (map_int[i_pos][j_pos] == - 1)
    {
        map_int[i_pos][j_pos] = 0;
        scene->removeItem(&(map_pix[i_pos][j_pos]));
    }
}

PacMan::PacMan(QGraphicsScene *scene) : QGraphicsPixmapItem()
{
    i_pos = 4;
    j_pos = 10;
    direction = 0;
    this->scene = scene;
    ft_create_map();
    this->setPixmap(QPixmap(":/pics/pacman_left.png"));
    this->setPos(j_pos * 64, i_pos * 64);
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
    if (this->direction == 1)
    {
        if (ft_check_move(this->i_pos - 1, this->j_pos))
        {
            ft_update_scene();
            this->i_pos--;
        }
    }
    if (this->direction == 2)
    {
        if (ft_check_move(this->i_pos + 1, this->j_pos))
        {
            ft_update_scene();
            this->i_pos++;
        }
    }
    if (this->direction == 3)
    {
        if (ft_check_move(this->i_pos, this->j_pos - 1))
        {
            ft_update_scene();
            this->j_pos--;
        }
    }
    if (this->direction == 4)
    {
        if (ft_check_move(this->i_pos, this->j_pos + 1))
        {
            ft_update_scene();
            this->j_pos++;
        }
    }
    this->setPos(this->j_pos * 64, this->i_pos * 64);
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



