#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int n = qMax<int>(3,5); // 5
    n = qMin<int>(3,5); // 3
    n = qAbs(-56); // 56
    n = qRound(5.2); // 5
    n = qRound(-5.2); // -5
    n = qBound(1,2,5); // == qMax(min, qMin(val,max))
    if (!qFuzzyCompare(12.0, 12.01)) { // Функция для сравнения чисел с плавающей запятой
        qDebug() << "Not Equal";
    }
    return a.exec();
}
