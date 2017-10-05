#include <gameclass.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameLoop    *loop;

    loop = new GameLoop();

    loop->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    loop->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    loop->setFixedSize(WIDTH, HEIGHT);
    loop->setSceneRect(0, 0, WIDTH, HEIGHT);
    loop->show();
    loop->ft_roll_game();
    return a.exec();
}
