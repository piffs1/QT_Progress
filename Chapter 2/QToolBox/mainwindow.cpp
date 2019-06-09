#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList strlst;

    strlst << "Linux" << "Windows" << "MacOSX" << "Android";

    for (QString str : strlst) {
        ui->toolBox->addItem(new QLabel(str,ui->toolBox),str);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
