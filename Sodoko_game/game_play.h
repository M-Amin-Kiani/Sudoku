#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include "include.h"

namespace Ui {
class game_play;
}

class game_play : public QMainWindow
{
    Q_OBJECT

public:
    explicit game_play(QWidget *parent = nullptr);
    ~game_play();

private slots:
    void on_pb00_1_clicked();
    void on_pb00_2_clicked();
    void on_pb00_3_clicked();
    void on_pb00_4_clicked();
    void on_pb00_5_clicked();
    void on_pb00_6_clicked();
    void on_pb00_7_clicked();
    void on_pb00_8_clicked();
    void on_pb00_9_clicked();
    void on_table_cellClicked(int row, int column);

    void on_solve_clicked();

    void on_actionNew_game_triggered();

    void on_pushButton_clicked();

    void on_close_btn_game_clicked();

    void on_next_game_clicked();

    void on_save_info_clicked();

private:
    Ui::game_play *ui;
    int Column, Row;
    void click__on_pb(int num);
};

#endif // GAME_PLAY_H
