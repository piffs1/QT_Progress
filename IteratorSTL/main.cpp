#include <QCoreApplication>
#include <QVector>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<int> vnNumbers;

    for(int i = 0;i < 6; i++)
        vnNumbers.push_back(i);

    for(QVector<int>::iterator it = vnNumbers.begin(); it != vnNumbers.end(); ++it) {
        qDebug() << *it;
    }

    return a.exec();
}
