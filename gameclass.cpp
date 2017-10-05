#include <gameclass.h>

void    GameLoop::ft_roll_game()
{
    QTimer  *timer;

    timer = new QTimer();
//    ft_set_score();
    QObject::connect(timer, SIGNAL(timeout()), pacman, SLOT(ft_move()));
    timer->start(500);
}

//void    GameLoop::ft_set_score()
//{
//    int i_pos;
//    int j_pos;

//    i_pos = pacman->ft_get_pacman_i();
//    j_pos = pacman->ft_get_pacman_j();
//    if (map_int[i_pos][j_pos] == -1)
//    {
//        map_int[i_pos][j_pos] = 0;
//        scene->removeItem(&(map_pix[i_pos][j_pos]));
//        score++;
//    }
//}

//void    GameLoop::ft_create_map()
//{
//    for (int i = 0; i < size_x; i++)
//    {
//        for (int j = 0; j < size_y; j++)
//        {
//            if (i == 0 || j == 0
//                    || i == size_x - 1 || j == size_y - 1)
//                map_int[i][j] = 1;
//            else
//                map_int[i][j] = -1;
//        }
//    }
//    for (int i = 0; i < size_x; i++)
//    {
//        for (int j = 0; j < size_y; j++)
//        {
//            if (map_int[i][j] == 1)
//            {
//                map_pix[i][j].setPixmap(QPixmap(":/pics/greystone.png"));
//                map_pix[i][j].setPos(j * 64, i * 64);
//                scene->addItem(&(map_pix[i][j]));
//            }
//            else
//            {
//                map_pix[i][j].setPixmap(QPixmap(":/pics/ball.png"));
//                map_pix[i][j].setPos(j * 64, i * 64);
//                scene->addItem(&(map_pix[i][j]));
//            }
//        }
//    }
//}

GameLoop::GameLoop()
{
    score = 0;
    lives = 3;
    scene = new QGraphicsScene();
    view = new QGraphicsView();
    this->setScene(scene);
//    ft_create_map();
    pacman = new PacMan(scene);
    pacman->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    pacman->setFocus();
}
