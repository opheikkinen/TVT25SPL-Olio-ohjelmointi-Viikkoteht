#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->countButton,&QPushButton::clicked,
            this,&MainWindow::handleClick);
    connect(ui->resetButton,&QPushButton::clicked,
            this,&MainWindow::resetDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::handleClick()
{
    ui->display->setText(QString::number(count++));
    qDebug() << count;
}

void MainWindow::resetDisplay()
{
    ui->display->clear();
    count = 1;
}

