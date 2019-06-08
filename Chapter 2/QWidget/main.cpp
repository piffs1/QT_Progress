#include "widget.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("My window");
    w.setEnabled(true);
    /// w.size();  /// QSize(400,300)
    /// QSize(QWidget::width, QWidget::height)

    /// w.pos() /// QPoint(w.x(),w.y())
    /// w.geometry() /// QRect(0,0, 400x300)
    /// w.move(QPoint(0,0)); /// Передвинуть виджет в координаты 0,0
    /// w.resize(100,80); /// изменить размер виджета
    /// w.setGeometry(0,0, 400, 300); /// Устанавливает QRect
    //QPalette pal1;
    //pal1.setColor(w.backgroundRole(), Qt::blue);
    //w.setPalette(pal1);
    //w.setAutoFillBackground(true); /// false по умолчанию, позволяет заполнять фон
    /// фон станет синим

    w.show();

    return a.exec();
}
