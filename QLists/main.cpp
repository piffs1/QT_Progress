#include <QCoreApplication>
#include <QList>
#include <QLinkedList>
#include <QDebug>

/// Важности
/// Лучше использовать метод empty() = isEmpty() нежели проверять через size()
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QLinkedList<int> lst1;
    QList<int> lst2;
    lst2 << 1 << 2 << 3 << 4 << 0;
    lst2.move(lst2.size()-1,0);
    /// move(from,to) перемещает from на позицию to
    qDebug() << lst2; /// 0 1 2 3 4
    /// lst2.removeFirst(); /// 1 2 3 4
    /// lst2.removeLast(); /// 0 1 2 3
    /// lst2.swap(i,j)
    /// <T> = lst2.takeFirst(),<T> = lst2.takeLast(),<T> = lst2.takeAt()
    /// Сначала возвращает элемент типа T
    /// Потом удаляет его. takeAt(pos) удаляет с позиции pos
    /// lst2.toSet() возвращает QSet
    /// toStdList() std::list
    /// toVector() std::vector
    for (auto it = lst2.begin(); it != lst2.end(); ++it) {
        qDebug() << "Element : " << *it;
    }

    return a.exec();
}
