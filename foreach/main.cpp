#include <QCoreApplication>
#include <QList>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> list;

    list << "One" << "Two" << "Three!";

    foreach (auto temp, list) { /// equals for (QString temp : list)
        qDebug() << "Element : " << temp;
    }


    return a.exec();
}
