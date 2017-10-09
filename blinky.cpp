#include "blinky.h"

void        Blinky::ft_calculate_point()
{
    if (!pacman->ft_scared_state())
    {
        i_exit = pacman->ft_get_pacman_i();
        j_exit = pacman->ft_get_pacman_j();
        this->setPixmap(QPixmap(":/pics/blinky.png"));
    }
    else
    {
        if (i_pos == 1 && j_pos == 1)
            pacman->ft_set_scared();
        else
        {
            this->setPixmap(QPixmap(":/pics/frightened.png"));
            i_exit = 1;
            j_exit = 1;
        }
    }
}

Blinky::Blinky(QGraphicsScene *sc, int **map, PacMan *pc) : Ghost()
{
    scene = sc;
    pacman = pc;

    i_pos = 8;
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
}

void        Blinky::ft_set_default()
{
    i_exit = i_pos;
    j_exit = j_pos;
    i_pos = 9;
    j_pos = 9;
    direction = 0;
    this->setPos(j_pos * 32, i_pos * 32);
}

void        Blinky::ft_set_friends(Pinky *pin, Clyde *cl, Inky *ink)
{
    pinky = pin;
    clyde = cl;
    inky = ink;
}

void        Blinky::ft_find_path()
{
    int i;
    int j;
    int k;

    map_path[pinky->ft_get_i_pos()][pinky->ft_get_j_pos()] = -5;
    map_path[clyde->ft_get_i_pos()][clyde->ft_get_j_pos()] = -5;
    map_path[inky->ft_get_i_pos()][inky->ft_get_j_pos()] = -5;
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
    map_path[pinky->ft_get_i_pos()][pinky->ft_get_j_pos()] = 0;
    map_path[clyde->ft_get_i_pos()][clyde->ft_get_j_pos()] = 0;
    map_path[inky->ft_get_i_pos()][inky->ft_get_j_pos()] = 0;
}

void        Blinky::ft_find_pacman()
{
    d = 0;
    flag = 0;
    map_path[i_pos][j_pos] = d;
    if (ft_check_intersect())
    {
        ft_clear_map();
        return ;
    }
    ft_find_path();
    if (ft_set_direction_near())
    {
        if (ft_check_intersect())
        {
            ft_clear_map();
            return ;
        }
    }
    ft_restore_path();
    ft_set_direction();
    ft_clear_map();
}

void    Blinky::ft_move_ghost()
{
    ft_calculate_point();
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
    if (ft_check_intersect())
        return ;
}
