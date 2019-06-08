#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList strlst;

    strlst << "Folders" << "UsedSpace";
    ui->treeWidget->setHeaderLabels(strlst);
    ui->treeWidget->setSortingEnabled(true);

    QTreeWidgetItem* ptwItem = new QTreeWidgetItem(ui->treeWidget);
    ptwItem->setText(0, "Local DICK(C)");

    QTreeWidgetItem* ptwItemDir = nullptr;
    for (int i = 1; i < 20; ++i) {
        ptwItemDir = new QTreeWidgetItem(ptwItem);
        ptwItemDir->setText(0, "Directory" + QString::number(i));
        ptwItemDir->setText(1,QString::number(i) + "MB ");
    }

    ptwItem->setExpanded(true); /// Сразу открыть ветку "<"
    QTreeWidgetItemIterator it(ui->treeWidget, QTreeWidgetItemIterator::All); /// F2
    while (*(++it)) {
        qDebug() << (*it)->text(0); /// Directory9...Directory0
    }
}


Widget::~Widget()
{
    delete ui;
}
