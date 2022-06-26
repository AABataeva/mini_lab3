#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

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

void MainWindow::paintEvent(QPaintEvent *event)
{
   QPainter painter(this);
   if(cnt > 1)
       rect.draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    cnt++;
    if(cnt == 1){
        x = event->x();
        y = event->y();
    }
    else if (cnt == 2){
        rect = Rect(x, y, event->x(), event->y());
        repaint();

    }
    else
    {
         QMessageBox Box;
        if(rect.contains(event->x(), event->y())){
            Box.setText("Попали");
            Box.exec();
        }
     else
        { Box.setText("Не попали");
          Box.exec();
        }
    }
   repaint();

}


