#ifndef GAME_HELPER_H
#define GAME_HELPER_H

#include <QMainWindow>

namespace Ui {
class game_helper;
}

class game_helper : public QMainWindow
{
    Q_OBJECT

public:
    explicit game_helper(QWidget *parent = nullptr);
    ~game_helper();

private slots:
    void on_back_to_mainpage_clicked();

private:
    Ui::game_helper *ui;
};

#endif // GAME_HELPER_H
