#include "game_helper.h"
#include "ui_game_helper.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

game_helper::game_helper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game_helper)
{
    ui->setupUi(this);
}

game_helper::~game_helper()
{
    delete ui;
}

void game_helper::on_back_to_mainpage_clicked()
{
    MainWindow *m = new MainWindow();
    this->close();
    m->show();
}
