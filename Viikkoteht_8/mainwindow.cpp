#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectTimer = new QTimer();
    setGameInfoText("Aloita peli valitsemalla aika.",14);


    connect(ui->shortGame,&QPushButton::clicked,this,
            &MainWindow::GameTimeSelect);
    connect(ui->longGame,&QPushButton::clicked,this,
            &MainWindow::GameTimeSelect);

    connect(ui->startButton,&QPushButton::clicked,this,
            &MainWindow::startGame);
    connect(ui->stopButton,&QPushButton::clicked,this,
            &MainWindow::stopGame);

    connect(ui->switchPlayer1,&QPushButton::clicked,this,
            &MainWindow::switchPlayer);
    connect(ui->switchPlayer2,&QPushButton::clicked,this,
            &MainWindow::switchPlayer);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectTimer;
    objectTimer=nullptr;
}

void MainWindow::updateProgressBar()
{

    ui->progressBar1->setValue(player1Time);
    ui->progressBar2->setValue(player2Time);

    if(player1Time<=0){
        objectTimer->stop();
        setGameInfoText("Pelaaja 2 voitti!",14);
    }else if(player2Time<=0){
        objectTimer->stop();
        setGameInfoText("Pelaaja 1 voitti!",14);
    }

}

void MainWindow::setGameInfoText(QString teksti, short koko)
{
    ui->label->setText(teksti);
    QFont font = ui->label->font();
    font.setPointSize(koko);
    ui->label->setFont(font);
}

void MainWindow::slotShowTimer()
{
    if(currentPlayer==1){
        player1Time--;
        ui->progressBar1->setValue(player1Time);
    }else if(currentPlayer==2){
        player2Time--;
        ui->progressBar2->setValue(player2Time);
    }

    updateProgressBar();
}

void MainWindow::GameTimeSelect()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if(name=="shortGame"){
        gameTime = 120;
    }else if(name=="longGame"){
        gameTime = 300;
    }

    setGameInfoText(QString("Pelin kesto valittu %1 sekuntia. Paina START").arg(gameTime),14);



}

void MainWindow::startGame()
{
    connect(objectTimer, SIGNAL(timeout()),this, SLOT(slotShowTimer()));
    objectTimer->start(1000);

    ui->progressBar1->setRange(0, gameTime);
    ui->progressBar2->setRange(0, gameTime);

    player1Time = gameTime;
    player2Time = gameTime;

    setGameInfoText("Peli käynnissä.",14);


}

void MainWindow::switchPlayer()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if(name=="switchPlayer1"){
        currentPlayer = 2;
    }else if(name=="switchPlayer2"){
        currentPlayer = 1;
    }
}

void MainWindow::stopGame()
{
    objectTimer->stop();

    currentPlayer = 1;

    setGameInfoText("Aloita uusi peli valitsemalla aika.",14);
}
