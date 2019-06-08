#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->lineEdit, SIGNAL(textChanged(const QString&)),
                     this, SLOT(setSignalTextChanged(const QString&)));
    /// textChanged(QString msg) -> Любое изменение текста. msg -> сообщение.

    QObject::connect(ui->lineEdit, SIGNAL(cursorPositionChanged(int, int)),
                     this, SLOT(setSignalCursorPositionChanged(int,int)));
    /// cursorPositionChanged(int arg1, int arg2) ->  Выделение текста от arg1 до arg2
    /// Пример: |Hello| everyone!  (|text| выделение text). В данном случае arg1=0, arg2=5
    /// Странный сигнал, если идти слева направо то [arg1..arg2)
    /// Если справа налево (arg1..arg2]

    QObject::connect(ui->lineEdit, SIGNAL(editingFinished()), this, SLOT(setSignalEditingFinished()));
    /// editingFinished() -> Вызывается, когда убираем курсор с нашего QLineEdit

    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(setSignalReturnPressed()));
    /// returnPressed() -> Нажатие клавиши enter

    QObject::connect(ui->lineEdit, SIGNAL(selectionChanged()), this, SLOT(setSignalSelectionChanged()));
    /// Измнение выделения (можно через мышь, можно через shift). Мда ...

    QObject::connect(ui->lineEdit, SIGNAL(textEdited(const QString&)), this, SLOT(setSignalTextEdited(const QString&)));
    /// Почти тоже самое что и textChanged отличие да хз

    /// Методы lineEdit
    /// ui->lineEdit_2->cut() /// CTRL+X
    /// ui->lineEdit_2->copy() CTRL+C
    /// ui->lineEdit_2->paste() CTRL+V
    /// undo() CTRL+Z
    /// redo() CTRL+Y

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSignalTextChanged(const QString &msg)
{
    qDebug() << "setSignalTextChanged(" << msg << ")";
    ui->lineEdit_2->setText(msg);
    ui->lineEdit_3->setText("textChanged(const QString&)");

}

void MainWindow::setSignalCursorPositionChanged(int arg1, int arg2)
{
    qDebug() << "setSignalCursorPositionChanged(" << arg1 << "," << arg2 << ")";
    ui->lineEdit_2->setText(QString(arg1) + " " + QString(arg2));
    ui->lineEdit_3->setText("cursorPositionChanged(int,int)");
}

void MainWindow::setSignalEditingFinished()
{
    qDebug() << "setSignalEditingFinished()";
    ui->lineEdit_3->setText("editingFinished()");
}

void MainWindow::setSignalReturnPressed()
{
    qDebug() << "setSignalReturnPressed()";
    ui->lineEdit_3->setText("returnPressed()");
}

void MainWindow::setSignalSelectionChanged()
{
    qDebug() << "setSignalSelectionChanged()";
    ui->lineEdit_3->setText("selectionChanged()");
}

void MainWindow::setSignalTextEdited(const QString& msg)
{
     qDebug() << "setSignalTextEdited(" << msg << ")";
     ui->lineEdit_2->setText(msg);
     ui->lineEdit_3->setText("textEdited(const QString& msg)");
}
