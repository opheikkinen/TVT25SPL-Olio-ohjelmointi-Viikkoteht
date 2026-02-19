#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    state = 1;

    ui->setupUi(this);

    connect(ui->N1,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N2,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N3,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N4,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N5,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N6,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N7,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N8,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N9,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);
    connect(ui->N0,&QPushButton::clicked,this,
            &MainWindow::numberClickHandler);

    connect(ui->add,&QPushButton::clicked,this,
            &MainWindow::addSubMulDiv);
    connect(ui->sub,&QPushButton::clicked,this,
            &MainWindow::addSubMulDiv);
    connect(ui->mul,&QPushButton::clicked,this,
            &MainWindow::addSubMulDiv);
    connect(ui->div,&QPushButton::clicked,this,
            &MainWindow::addSubMulDiv);

    connect(ui->enter,&QPushButton::clicked,this,
            &MainWindow::clearAndEnter);
    connect(ui->clear,&QPushButton::clicked,this,
            &MainWindow::resetDisplays);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    if(state==1){
        QPushButton * button = qobject_cast<QPushButton*>(sender());
        QString name = button->objectName();
        QString prevDis = ui->num1Dis->text();
        ui->num1Dis->setText(prevDis+button->text());
        qDebug() << "Button name:" << name;
    }else{
        QPushButton * button = qobject_cast<QPushButton*>(sender());
        QString name = button->objectName();
        QString prevDis = ui->num2Dis->text();
        ui->num2Dis->setText(prevDis+button->text());
        qDebug() << "Button name:" << name;
    }
}

void MainWindow::clearAndEnter()
{

    float n1 = ui->num1Dis->text().toFloat();
    float n2 = ui->num2Dis->text().toFloat();

    qDebug() << "number 1 = "<< n1 <<" and number 2 = "<< n2;

    switch(operand){
    case 0:
        result = n1+n2;
        break;
    case 1:
        result = n1-n2;
        break;
    case 2:
        result = n1*n2;
        break;
    case 3:
        result = n1/n2;
        break;
    }

    ui->resultDis->setText(QString::number(result));
}

void MainWindow::addSubMulDiv()
{
    state = 2;
    qDebug() << "state vaihto";

    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if(name=="add"){
        operand = 0;
    }else if(name=="sub"){
        operand = 1;
    }else if(name=="mul"){
        operand = 2;
    }else{
        operand = 3;
    }

    qDebug() << "Button name: " << name << "operand: " << operand;
}

void MainWindow::resetDisplays()
{
    ui->num1Dis->clear();
    ui->num2Dis->clear();
    ui->resultDis->clear();
    state = 1;
}
