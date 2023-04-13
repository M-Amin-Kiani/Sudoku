#include "mainwindow.h"
#include "login_page.h"
#include "game_helper.h"
#include <QApplication>
#include "windows.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
