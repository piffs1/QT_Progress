#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pnameValidator = new NameValidator(ui->lineEdit);
    ui->lineEdit->setValidator(m_pnameValidator);
    ui->label->setBuddy(ui->lineEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}
