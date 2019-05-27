#include <QCoreApplication>
#include <QSet>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> set1 = {"Ar", "Br", "Cr", "Dr"};
    QSet<QString> set2 = {"Dr", "Mr"};
    QSet<QString> setResult = set1;
    qDebug() << "UNION IS " << setResult.unite(set2); /// Ar, Mr, Cr, Dr, Mr
    qDebug() << "INTERSECTION IS " << set1.intersect(set2).toList(); /// Dr
    qDebug() << "Разность setResult and set2 IS " << setResult.subtract(set2); /// Cr, Br, Ar

    return a.exec();
}
