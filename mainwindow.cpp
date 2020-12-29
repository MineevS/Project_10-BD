#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwindow_1.h"
#include "ui_mainwindow_1.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, SIGNAL(triggered()), this, SLOT(func_Win()));
}

void MainWindow::func_Win()
{
    auto Win_1 = new MainWindow_1;

    Win_1->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

