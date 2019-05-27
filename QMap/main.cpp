#include <QCoreApplication>
#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<int,int> map1;
    map1.insert(1,1);
    map1.insert(1,2);
    map1.insertMulti(1,3);  /// Опасная вещь
    map1.insert(2,54);
    /// если ключ уже существует, то insert заменяет
    /// старое значение на новое
    /// insertMulti вставляет может добавить без замены
    /// т.е. при insert(1,1); insertMulti(1,2) существовать будут две эти пары
    /// через итератор возможно получить доступ к новому значению,
    /// но через [] нельзя

    for (auto it = map1.begin(); it!= map1.end(); ++it) {
        qDebug() << it.key() << " " << it.value();
    }
    qDebug() << map1[1];
    qDebug() << map1.keys(); /// 1 , 1 , 2
    /// qDebug() << map1.unite(map) /// Объединяет контейнеры map
    qDebug() << map1.values(); /// 3, 2, 54
    if (!map1.contains(3)) {    ///
        map1[3] = 3;
    }

    return a.exec();
}
