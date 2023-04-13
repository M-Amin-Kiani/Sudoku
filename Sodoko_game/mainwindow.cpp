#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login_page.h"
#include "ui_login_page.h"
#include "game_helper.h"
#include "ui_game_helper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_to_login_page_clicked()
{
    login_page *l = new login_page();
    this->close();
    l->show();
}

void MainWindow::on_help_btn_clicked()
{
    game_helper *h = new game_helper();
    this->close();
    h->show();
}
