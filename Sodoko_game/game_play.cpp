#include "game_play.h"
#include "ui_game_play.h"
#include "login_page.h"
#include "ui_login_page.h"
#include "QLabel"
#include "QDate"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QString"

sudoku::matrix matx;

game_play::game_play(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game_play)
{
    ui->setupUi(this);

    QString jari_date = QDate::currentDate().toString();
    QLabel *jari_date_label = new QLabel(jari_date);
    ui->statusbar->addWidget(jari_date_label);

    matx.new_puzzle();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.read(i, j))
            {
                QColor c(122,122,235);
                Cell->QTableWidgetItem::setBackground(c);
            }
        }
    }
    ui->label->setText("sudoku!!");
}

game_play::~game_play()
{
    delete ui;
}

void game_play::on_table_cellClicked(int row, int column)
{
    Row = row;
    Column = column;
    QString str = "";
    str += '0' + row;
    str += ',';
    str += '0' + column;
    const QString cstr = str;
    ui->label->setText(cstr);
}

void game_play::click__on_pb(int num)
{
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, num);
    QString str = "";
    str += '0' + matx.read(Row, Column);
    const QString cstr = str;
    Cell->setText(cstr);
    if (matx.you_win())
    {
        ui->label->setText("you win!!");
    }
}

void game_play::on_pb00_1_clicked()
{
   click__on_pb(1);
}

void game_play::on_pb00_2_clicked()
{
    click__on_pb(2);
}

void game_play::on_pb00_3_clicked()
{
    click__on_pb(3);
}

void game_play::on_pb00_4_clicked()
{
    click__on_pb(4);
}

void game_play::on_pb00_5_clicked()
{
    click__on_pb(5);
}

void game_play::on_pb00_6_clicked()
{
    click__on_pb(6);
}

void game_play::on_pb00_7_clicked()
{
    click__on_pb(7);
}

void game_play::on_pb00_8_clicked()
{
    click__on_pb(8);
}

void game_play::on_pb00_9_clicked()
{
    click__on_pb(9);
}

void game_play::on_solve_clicked()
{
    matx.reset();
    matx.solve();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i,j);
            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}

void game_play::on_actionNew_game_triggered()
{
    matx.new_puzzle();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.read(i, j))
            {
                QColor c(122,122,235);
                Cell->QTableWidgetItem::setBackground(c);
            }
            else
            {
                QColor c(255,255,255);
                Cell->QTableWidgetItem::setBackground(c);
            }
        }
    }
}

void game_play::on_pushButton_clicked()
{
    matx.reset();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}


void game_play::on_close_btn_game_clicked()
{
    this->close();
}

qint16 game_over_player = 0;  // avoid getting 0 gime-over and staying the game-over's value  ( int = qint16 -->cause problem with int )
void game_play::on_next_game_clicked()
{
    bool seeker = false;
    QString user = ui->player_name->text(), pass = ui->player_pass->text();
    QFile fgi("E:/best codes of me/sodoku game/mini-project-2-sudoku-M-Amin-Kiani/Sodoko_game/login_user.txt");
    fgi.open(QFile::ReadOnly | QFile::Text);
    QTextStream content(&fgi);
    QString line_checker, line_checker2;
    line_checker = content.readLine();

    if(user == line_checker)
    {
        line_checker2 = content.readLine();
        if(pass == line_checker2)
        {
            seeker = true;
            game_over_player = 0;
            game_play::close();
            game_play *newgp = new game_play();
            newgp->show();
        }
        else
        {
            if (game_over_player == 2)
            {
                QMessageBox :: critical(this,"sing-up","you were banned by the author.\ntry again later...!");
                game_play::close();
                game_play *newgp = new game_play();
                newgp->show();
            }
            else
            {
                QMessageBox :: warning(this,"sing-up","user or pass is wrong!\nplease try again...");
            }
            if(pass == line_checker2)
            {
                seeker = true;
                game_over_player = 0;
                game_play::close();
                game_play *newgp = new game_play();
                newgp->show();
            }
            game_over_player++;
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
                    game_over_player=0;
                    game_play::close();
                    game_play *newgp = new game_play();
                    newgp->show();
                }
            }
        }
        if(seeker == false)
        {
            if (game_over_player == 2)
            {
                QMessageBox :: critical(this,"sing-up","you were banned by the author.\ntry again later...!");
                game_play::close();
                game_play *newgp = new game_play();
                newgp->show();
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
                        game_over_player=0;
                        game_play::close();
                        game_play *newgp = new game_play();
                        newgp->show();
                    }
                }
            }
            game_over_player++;
        }

    }
    fgi.close();

    QString point = ui->player_point->text();
    if(point == 0)
    {
        QMessageBox :: warning(this,"sing-up","your are a guest!\nplease Sign-in first...");
    }
}

void game_play::on_save_info_clicked()
{
    QString user = ui->player_name->text(), point = ui->player_point->text(), line_checker;
    QFile fg("E:/best codes of me/sodoku game/mini-project-2-sudoku-M-Amin-Kiani/Sodoko_game/game_info_user.txt");
    fg.open(QFile::ReadWrite | QFile::Text);
    QTextStream write(&fg), content(&fg);
    line_checker = content.readLine();

    if(line_checker == "")
    {
        write<<user<<endl;
        write<<point<<endl;
    }
    else
    {
        while(!line_checker.isNull())
        {
            line_checker = content.readLine();
            if(line_checker == "")
            {
                write<<user<<endl;
                write<<point<<endl;
            }
        }
    }
    fg.close();

    QMessageBox::information(this,"Save_Game","save was succesfuly...\nWelcome to the next Game!");
}
