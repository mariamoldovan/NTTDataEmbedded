#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QColor>
//#include "senzor.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // initGUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}




