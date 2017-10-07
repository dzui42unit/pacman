#include "blinky.h"
#include <iostream>

Blinky::Blinky(QGraphicsScene *sc, int **map, PacMan *pc)
{
    scene = sc;
    pacman = pc;

    counter = 0;
    i_pos = 9;
    j_pos = 9;
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (map[i][j] == 1)
                map_path[i][j] = -5;
            else
                map_path[i][j] = -3;
        }
    }
    this->setPixmap(QPixmap(":/pics/blinky.png"));
    this->setPos(j_pos * 32, i_pos * 32);
    scene->addItem(this);
    ft_find_pacman();
}

void        Blinky::ft_set_default()
{
    i_pos = 9;
    j_pos = 9;

    i_exit = i_pos;
    j_exit = j_pos;
    counter = 0;
    direction = 0;
    this->setPos(j_pos * 32, i_pos * 32);
}

int         Blinky::ft_set_direction_near()
{
    int flag;

    flag = 0;
    if (i_pos + 1 < size_x)
    {
        if (i_pos + 1 == i_exit && j_pos == j_exit)
        {
            direction = 2;
            flag = 1;
        }
    }
    if (i_pos - 1 >= 0)
    {
        if (i_pos -1 == i_exit && j_pos == j_exit)
        {
            direction = 1;
            flag = 1;
        }
    }
    if (j_pos + 1 < size_x)
    {
        if (i_pos == i_exit && j_pos + 1 == j_exit)
        {
            direction = 4;
            flag = 1;
        }
    }
    if (j_pos - 1 < size_x)
    {
        if (i_pos == i_exit && j_pos - 1 == j_exit)
        {
            direction = 3;
            flag = 1;
        }
    }
    if (flag)
        return (1);
    return (0);
}

void        Blinky::ft_clear_map()
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (map_path[i][j] != -5)
                map_path[i][j] = -3;
        }
    }
}

void        Blinky::ft_restore_path()
{
    int i;
    int j;
    int k;

    i = i_exit;
    j = j_exit;
    while (d > 0)
    {
        d--;
        k = 0;
        while (k < 4)
        {
            i_x = i + x_dir[k];
            i_y = j + y_dir[k];
            if (i_x >= 0 && i_x < size_x
                && i_y >= 0 && i_y < size_y && map_path[i_x][i_y] == d)
            {
                map_path[i_x][i_y] = -4;
                i = i + x_dir[k];
                j = j + y_dir[k];
                break ;
            }
            k++;
        }
    }
}

void        Blinky::ft_set_direction()
{
    if (i_pos + 1 < size_x)
    {
        if (map_path[i_pos + 1][j_pos] == -4)
            direction = 2;
    }
    if (i_pos - 1 >= 0)
    {
        if (map_path[i_pos - 1][j_pos] == -4)
            direction = 1;
    }
    if (j_pos + 1 < size_x)
    {
        if (map_path[i_pos][j_pos + 1] == -4)
            direction = 4;
    }
    if (j_pos - 1 < size_x)
    {
        if (map_path[i_pos][j_pos - 1] == -4)
            direction = 3;
    }
}

void        Blinky::ft_find_pacman()
{
    int i;
    int j;
    int k;

    d = 0;
    flag = 0;
    if (pacman->ft_scared_state())
    {
        i_exit = 1;
        j_exit = 1;
        if (counter == 0)
            counter = 30;
    }
    else
    {
        i_exit = pacman->ft_get_pacman_i();
        j_exit = pacman->ft_get_pacman_j();
    }
    map_path[i_pos][j_pos] = d;
    if (i_pos == i_exit && j_pos == j_exit
            && !pacman->ft_scared_state())
    {
        ft_clear_map();
        pacman->ft_set_defaut();
        ft_set_default();
        return ;
    }
    if (i_pos == pacman->ft_get_pacman_i() && j_pos == pacman->ft_get_pacman_j()
            && pacman->ft_scared_state())
    {
        ft_clear_map();
        ft_set_default();
        this->setPixmap(QPixmap(":/pics/blinky.png"));
        pacman->ft_set_scared();
        return ;
    }
    while (!flag && map_path[i_exit][j_exit] == -3)
    {
        i = 0;
        flag = 1;
        while (i < size_x)
        {
            j = 0;
            while (j < size_y)
            {
                if (map_path[i][j] == d)
                {
                    k = 0;
                    while (k < 4)
                    {
                        i_x = x_dir[k] + i;
                        i_y = y_dir[k] + j;
                        if ((i_x >= 0 && i_x < size_x)
                            && (i_y >= 0 && i_y < size_y) && (map_path[i_x][i_y] == -3))
                        {
                            map_path[i_x][i_y] = d + 1;
                            flag = 0;
                        }
                        k++;
                    }
                }
                j++;
            }
            i++;
        }
        d++;
    }
    if (ft_set_direction_near())
    {
        ft_clear_map();
        return ;
    }
    ft_restore_path();
    ft_set_direction();
    ft_clear_map();
}

int     Blinky::ft_check_move(int i_pos, int j_pos)
{
    if (map_path[i_pos][j_pos] == -5)
        return (0);
    return (1);
}

void    Blinky::ft_move_ghost()
{
    if (counter)
        this->setPixmap(QPixmap(":/pics/frightened.png"));
    ft_find_pacman();
    if (direction == 1)
    {
        if (ft_check_move(i_pos - 1, j_pos))
            i_pos--;
    }
    if (direction == 2)
    {
        if (ft_check_move(i_pos + 1, j_pos))
            i_pos++;
    }
    if (direction == 3)
    {
        if (ft_check_move(i_pos, j_pos - 1))
            j_pos--;
    }
    if (direction == 4)
    {
        if (ft_check_move(i_pos, j_pos + 1))
            j_pos++;
    }
    this->setPos(j_pos * 32, i_pos * 32);
    if (counter > 0)
    {
        counter--;
        if (counter == 0)
        {
            this->setPixmap(QPixmap(":/pics/blinky.png"));
            pacman->ft_set_scared();
        }
    }
}
