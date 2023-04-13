#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include <QMainWindow>

namespace Ui {
class login_page;
}

class login_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_page(QWidget *parent = nullptr);
    ~login_page();

private slots:
    void on_back_to_mainwindoww_clicked();

    void on_close_btn_log_clicked();

    void on_refresh_btn_log_clicked();

    void show_current_time();


    void on_sign_in_clicked();

    void on_sign_up_clicked();

    void on_guest_clicked();

private:
    Ui::login_page *ui;
};

#endif // LOGIN_PAGE_H
