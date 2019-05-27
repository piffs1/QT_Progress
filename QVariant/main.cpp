#include <QCoreApplication>
#include <QVariant>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /// QVariant::typeToName(QVariant(12.0).type()); /// double
    /// QVariant::typeToName(QVariant(true).type()); /// bool

    /// int(12) + QVariant(12.0).toInt(nullptr); /// 24
    /// QVariant(12.0).value<int>();    /// Используется, когда необходим перевод в QPixmap etc..
    return a.exec();
}
