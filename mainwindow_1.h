#ifndef MAINWINDOW_1_H
#define MAINWINDOW_1_H

#include <QMainWindow>

namespace Ui {
class MainWindow_1;
}

class MainWindow_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_1(QWidget *parent = nullptr);
    ~MainWindow_1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow_1 *ui;
};

#endif // MAINWINDOW_1_H
