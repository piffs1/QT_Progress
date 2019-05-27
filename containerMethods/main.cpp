#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> strList1;
    QList<QString> strList2;
    QList<QString> strSumList1AndList2; /// UncleBob

    strList1 << "One" << "Two";
    strList2 << "Three" << "Four";

    strSumList1AndList2 = strList1 + strList2;

    qDebug() << strSumList1AndList2; /// "One", "Two", "Three", "Four"

    strSumList1AndList2+= "Five"; /// += equals <<

    qDebug() << strSumList1AndList2; /// "One", "Two", "Three", "Four", "Five"

    if (strSumList1AndList2.size()) { /// back() == last(), ВАЖНО ДЕЛАТЬ ПРОВЕРКУ НА РАЗМЕР КОНТЕЙНЕРА, иначе ассерт
        qDebug() << strSumList1AndList2.back();
    }

    if (strSumList1AndList2.contains("Two")) {
        qDebug() << "Value \"Two\" contains in strSumList1AndList2!";
        /// очень удобный метод
    }

    int firstPosition = strSumList1AndList2.indexOf("Three",0); /// 2
    /// int firstPosition = strSumList1AndList2.indexOf("Three",3); /// -1
    /// indexOf(searchElement, fromPositionInList = 0)
    /// lastIndexOf находит последнее вхождение
    /// Находит первое вхождение searchElement, от fromPositionInList до конца списка
    /// В противном случае выводит -1

    ///    qDebug() << strList1.mid(5, 2); /// empty
    qDebug() << strList1.mid(0, 7);
    /// mid(fromPosition, length)
    /// "One", "Two" если выход за границы, копируется полный контейнер

    /// replace(position, value)
    /// strList1.repace(0, "Four") "Four", "Two"

    /// container.erase(iter) удаление элемента на позиции итератора
    strSumList1AndList2.erase(strSumList1AndList2.begin(), strSumList1AndList2.end()); /// erase(от, до)

    /// qDebug() << strSumList1AndList2; /// empty
    /// (STL) container.first() == (QT) container.front()

    return a.exec();
}
