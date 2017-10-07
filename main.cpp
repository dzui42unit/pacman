#include <gameclass.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameLoop    *loop;

    if (argc == 1 || argc > 2)
    {
        std::cout << "Invalid number of parameters.\n";
        std::cout << "Usage: ./pacman maps/map.txt\n";
        exit(0);
    }

    loop = new GameLoop(argv[1]);

    loop->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    loop->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    loop->setFixedSize(WIDTH, HEIGHT);
    loop->setSceneRect(0, 0, WIDTH, HEIGHT);
    loop->show();
    loop->ft_roll_game();
    return a.exec();
}
