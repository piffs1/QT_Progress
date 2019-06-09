#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList strlist;
    strlist << "Windows" << "Android" << "MacOSX" << "Linux";
    foreach(QString str, strlist) {
        ui->tabWidget->addTab(new QLabel(str, ui->tabWidget),str);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
