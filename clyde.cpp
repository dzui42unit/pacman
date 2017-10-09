#include "clyde.h"
#include <cmath>

Clyde::Clyde(QGraphicsScene *sc, int **map, PacMan *pc) : Ghost()
{
    scene = sc;
    pacman = pc;

    i_pos = 9;
    j_pos = 8;
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
    this->setPixmap(QPixmap(":/pics/clyde.png"));
    this->setPos(j_pos * 32, i_pos * 32);
    scene->addItem(this);
}

void        Clyde::ft_find_pacman()
{
    d = 0;
    flag = 0;
    if (!pacman->ft_scared_state())
    {
        this->setPixmap(QPixmap(":/pics/clyde.png"));
        ft_calculate_point();
    }
    else
    {
        if (i_pos == size_x - 2 && j_pos == size_y - 2)
            pacman->ft_set_scared();
        else
        {
            this->setPixmap(QPixmap(":/pics/frightened.png"));
            i_exit = size_x - 2;
            j_exit = size_y - 2;
        }
    }
    map_path[i_pos][j_pos] = d;
    if (ft_check_intersect())
        return ;
    ft_find_path();
    if (ft_set_direction_near())
    {
        ft_clear_map();
        return ;
    }
    ft_restore_path();
    ft_set_direction();
    ft_clear_map();
}

void        Clyde::ft_find_path()
{
    int i;
    int j;
    int k;

    map_path[blinky->ft_get_i_pos()][blinky->ft_get_j_pos()] = -5;
    map_path[pinky->ft_get_i_pos()][pinky->ft_get_j_pos()] = -5;
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
    map_path[blinky->ft_get_i_pos()][blinky->ft_get_j_pos()] = 0;
    map_path[pinky->ft_get_i_pos()][pinky->ft_get_j_pos()] = 0;
    map_path[inky->ft_get_i_pos()][inky->ft_get_j_pos()] = 0;
}

void        Clyde::ft_set_default()
{
    i_pos = 9;
    j_pos = 8;

    i_exit = i_pos;
    j_exit = j_pos;
    direction = 0;
    this->setPos(j_pos * 32, i_pos * 32);
}

void        Clyde::ft_calculate_point()
{
    int distance;

    distance = pow(i_pos - pacman->ft_get_pacman_i(), 2);
    distance += pow(j_pos - pacman->ft_get_pacman_j(), 2);
    distance = sqrt(distance);
    if (distance <= 8)
    {
        i_exit = pacman->ft_get_pacman_i();
        j_exit = pacman->ft_get_pacman_j();
    }
    else
    {
        i_exit = size_x - 2;
        j_exit = 1;
    }
    this->setPixmap(QPixmap(":/pics/clyde.png"));
}

void        Clyde::ft_set_friends(Blinky *bl, Pinky *pnc, Inky *ink)
{
    blinky = bl;
    pinky = pnc;
    inky = ink;
}

void    Clyde::ft_move_ghost()
{
    if (pacman->ft_get_point() >= 90)
    {
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
}
