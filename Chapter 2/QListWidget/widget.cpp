#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList strlist;
    QListWidgetItem* pItem;
    strlist << "Windows" << "Linux" << "Android" << "Mac OS";
    foreach(QString str, strlist) {
        pItem = new QListWidgetItem(str,ui->listWidget);
        pItem->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
        /// Флаги применяются только к айтему, т.е. в виджете могут быть
        /// Editable и non-editable элементы одновременно
    }
    ui->listWidget->insertItem(0,"Unix"); /// listWidget Unix Windows ... Mac Os
    ui->listWidget->insertItems(2,strlist); /// Unix Windows Windows ... Mac OS
    ui->listWidget->addItem("Solaris"); /// инсерт в конец
    ui->listWidget->setSelectionMode(QAbstractItemView::NoSelection); /// Но достать элемент через currentRow() возможно
    ui->listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listWidget->sortItems(Qt::DescendingOrder); /// AscendingOrder по нарастающей, Dsc в другую
    /// ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    /// insertItem(int row, item) -> row куда вставить(нумерация сверху вниз)

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->lineEdit->setText("Выбран элемент #" + QString::number(ui->listWidget->currentRow() + 1) + " : " + ui->listWidget->currentItem()->text());
}

