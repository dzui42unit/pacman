#include "gameclass.h"
#include "blinky.h"

int     GameLoop::ft_check_file_inp(std::string str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '4')
            return (1);
        i++;
    }
    return (0);
}

void    GameLoop::ft_roll_game()
{
    QTimer  *timer_pacman;
    QTimer  *timer_blinky;

    timer_pacman = new QTimer();
    timer_blinky = new QTimer();
    QObject::connect(timer_pacman, SIGNAL(timeout()), pacman, SLOT(ft_move()));
    timer_pacman->start(300);
    QObject::connect(timer_blinky, SIGNAL(timeout()), blinky, SLOT(ft_move_ghost()));
    timer_blinky->start(300);
}

void    GameLoop::ft_create_map()
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (map_int[i][j] == 1)
            {
                map_pix[i][j].setPixmap(QPixmap(":/pics/greystone.png"));
                map_pix[i][j].setPos(j * 32, i * 32);
                scene->addItem(&(map_pix[i][j]));
            }
            if (map_int[i][j] == 3)
            {
                map_pix[i][j].setPixmap(QPixmap(":/pics/ball.png"));
                map_pix[i][j].setPos(j * 32, i * 32);
                scene->addItem(&(map_pix[i][j]));
            }
            if (map_int[i][j] == 4)
            {
                map_pix[i][j].setPixmap(QPixmap(":/pics/energizer.png"));
                map_pix[i][j].setPos(j * 32, i * 32);
                scene->addItem(&(map_pix[i][j]));
            }
        }
    }
}

void    GameLoop::ft_write_line_map(int *map, std::string str)
{
    for (int i = 0; i < size_y; i++)
        map[i] = str[i] - '0';
}
GameLoop::GameLoop(char *file_name)
{
    std::ifstream   input;
    std::string     temp;
    int             nb;

    map_int = new int *[size_x];
    map_pix = new QGraphicsPixmapItem *[size_x];
    for (int i = 0; i < size_x; i++)
    {
        map_int[i] = new int[size_y];
        map_pix[i] = new QGraphicsPixmapItem[size_y];
    }

    input.open(file_name);
    if (input.is_open())
    {
        nb = 0;
        while (std::getline(input, temp))
        {
            if (temp.length() != size_y)
            {
                std::cout << "File error 1.\n";
                exit(0);
            }
            if (ft_check_file_inp(temp))
            {
                std::cout << "File error 3.\n";
                exit(0);
            }
            ft_write_line_map(map_int[nb], temp);
            nb++;
        }
        if (nb != size_x)
        {
            std::cout << "File error 2.\n";
            exit(0);
        }
        input.close();
    }
    else
    {
        std::cout << "File missing: " << file_name << ".\n";
        exit(0);
    }
    scene = new QGraphicsScene();
    view = new QGraphicsView();
    this->setScene(scene);
    ft_create_map();
    this->setStyleSheet("background-color:black;");
    pacman = new PacMan(map_int, map_pix, scene);
    pacman->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    pacman->setFocus();
    blinky = new Blinky(scene, map_int, pacman);
}
