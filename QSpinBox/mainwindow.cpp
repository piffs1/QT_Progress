#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setRange(1,100);
    ui->spinBox->setSuffix(" MB");
    ui->spinBox->setButtonSymbols(QSpinBox::PlusMinus);
    ui->spinBox->setWrapping(true); /// Прокрутка
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

MainWindow::~MainWindow()
{
    delete ui;
}
