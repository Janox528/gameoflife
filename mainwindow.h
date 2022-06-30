#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamewidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GameWidget* gw;
    void keyPressEvent(QKeyEvent *event);



private slots:
    void setsizescroll();
    void setGameMode();
    void startSnake();



    void setCellMode();




    void on_spinBox_size_editingFinished();

private:
    Ui::MainWindow *ui;
    int lastDirection;

};

#endif // MAINWINDOW_H
