#include "mainwindow.h"
#include "validation.h"
#include "check.h"
#include "number.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_validateButton_clicked()
{
    check mycheck;
    mycheck.setModal(true);
    mycheck.exec();
}


void MainWindow::on_missingButton_clicked()
{
    number mymissingnum;
    mymissingnum.setModal(true);
    mymissingnum.exec();
}

