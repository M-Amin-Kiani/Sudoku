#include "login_page.h"
#include "ui_login_page.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game_play.h"
#include "ui_game_play.h"
#include "qtimer.h"
#include "QTime"
#include "QFile"
#include "QString"
#include "QDebug"
#include "QMessageBox"

login_page::login_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login_page)
{
    ui->setupUi(this);
    QTimer *login_timer = new QTimer(this);
    connect(login_timer, SIGNAL(timeout()), this, SLOT(show_current_time()));
    login_timer->start();
}

void login_page::show_current_time()
{
    QTime login_time = QTime::currentTime();
    QString time_text = login_time.toString("hh : mm : ss");
    ui->time_jari->setText(time_text);
}

login_page::~login_page()
{
    delete ui;
}

void login_page::on_back_to_mainwindoww_clicked()
{
    MainWindow *mw = new MainWindow();
    this->close();
    mw->show();
}

void login_page::on_close_btn_log_clicked()
{
    this->ui->name_geetter->clear();
    this->ui->pass_getter->clear();
}

void login_page::on_refresh_btn_log_clicked()
{
    this->close();
}

void login_page::on_sign_in_clicked()
{
    QString user = ui->name_geetter->text(), pass = ui->pass_getter->text(), line_checker;
    QFile f("E:/best codes of me/sodoku game/mini-project-2-sudoku-M-Amin-Kiani/Sodoko_game/login_user.txt");
    f.open(QFile::ReadWrite | QFile::Text);
    QTextStream write(&f), content(&f);
    line_checker = content.readLine();

    if(line_checker == "")
    {
        write<<user<<endl;
        write<<pass<<endl;
    }
    else
    {
        while(!line_checker.isNull())
        {
            line_checker = content.readLine();
            if(line_checker == "")
            {
                write<<user<<endl;
                write<<pass<<endl;
            }
        }
    }
    f.close();

    QMessageBox::information(this,"Sign-in","Sign in was succesfuly...\nWelcome to the Game!");
}

qint16 game_over_user = 0;  // avoid getting 0 gime-over and staying the game-over's value  ( int = qint16 -->cause problem with int )
void login_page::on_sign_up_clicked()
{
    bool seeker = false;
    QString user = ui->name_geetter->text(), pass = ui->pass_getter->text();
    QFile f("E:/best codes of me/sodoku game/mini-project-2-sudoku-M-Amin-Kiani/Sodoko_game/login_user.txt");
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream content(&f);
    QString line_checker, line_checker2;
    line_checker = content.readLine();

    if(user == line_checker)
    {
        line_checker2 = content.readLine();
        if(pass == line_checker2)
        {
            seeker = true;
            game_over_user = 0;
            login_page::close();
            game_play *g = new game_play();
            g->show();
        }
        else
        {
            if (game_over_user == 2)
            {
                QMessageBox :: critical(this,"sing-up","you were banned by the author.\ntry again later...!");
                login_page::close();
                MainWindow *mwd = new MainWindow();
                mwd->show();
            }
            else
            {
                QMessageBox :: warning(this,"sing-up","user or pass is wrong!\nplease try again...");
            }
            if(pass == line_checker2)
            {
                seeker = true;
                game_over_user = 0;
                login_page::close();
                game_play *g = new game_play();
                g->show();
            }
            game_over_user++;
        }
    }
    else
    {
        while(!line_checker.isNull())
        {
            line_checker = content.readLine();
            if(user == line_checker)
            {
                line_checker2 = content.readLine();
                if(pass == line_checker2)
                {
                    seeker = true;
                    game_over_user=0;
                    login_page::close();
                    game_play *gp = new game_play();
                    gp->show();
                }
            }
        }
        if(seeker == false)
        {
            if (game_over_user == 2)
            {
                QMessageBox :: critical(this,"sing-up","you were banned by the author.\ntry again later...!");
                login_page::close();
                MainWindow *mwd = new MainWindow();
                mwd->show();
            }
            else
            {
                QMessageBox :: warning(this,"sing-up","user or pass is wrong!\nplease try again...");
            }
            while(!line_checker.isNull())
            {
                line_checker = content.readLine();
                if(user == line_checker)
                {
                    line_checker2 = content.readLine();
                    if(pass == line_checker2)
                    {
                        seeker = true;
                        game_over_user=0;
                        login_page::close();
                        game_play *gp = new game_play();
                        gp->show();
                    }
                }
            }
            game_over_user++;
        }

    }
    f.close();
}


void login_page::on_guest_clicked()
{
    login_page::close();
    game_play *gmp = new game_play();
    gmp->show();
}
