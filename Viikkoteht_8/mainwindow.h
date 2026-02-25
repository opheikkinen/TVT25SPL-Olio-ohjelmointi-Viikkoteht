#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer * objectTimer;
    void updateProgressBar();
    void setGameInfoText(QString,short);
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;

public slots:
    void slotShowTimer();

private slots:
    void GameTimeSelect();
    void startGame();
    void switchPlayer();
    void stopGame();
};
#endif // MAINWINDOW_H
