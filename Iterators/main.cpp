#include <QCoreApplication>
#include <QList>
#include <QDebug>

/// Итераторы Java стиля

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /// Java style
    QList<QString> list;
    list << "First" << "Second" << "Third";
    QListIterator<QString> it(list);
    /// QLinkedListIterator<T> it(QLinkedList<T>&);
    /// QVectorIterator<T> it(QVector<T>&);
    /// QHashIterator<Key, T> it(QHash<Key,T>&);
    /// QMapIterator<K,T> it(QMap<K,T>&);
    /// QSetIterator<K,T> it(QSet<K,T>&)
    if (it.findNext("Second")) { /// Поиск вперед. Если итератор будет на элементе со значеним "Second"
        qDebug() << "Element Second found";        /// А искомое значение будет "First", результат будет false
    } else {                     /// findPrevious аналогично в другую сторону
        qDebug() << "Not found :(";
    }
    /// При findNext итератор сдвигается, т.е.
    /// В данном случание it будет в значении Second
    it.toFront(); /// Перемещение итератора в начало списка
    while (it.hasNext()) {
        qDebug() << "Element : " << it.next();
        /// Возвращение следующего итератора
        /// И перемещает итератор
        /// Если итератор был бы на значении Second
        /// То при вызове it.next() он бы вывел значение Third
        /// и завершился
    }
    it.toBack();
    qDebug() << it.peekPrevious(); /// it.peekNext();
    /// Узнает значение след итератора
    /// Без изменения самого итератора
    if (it.hasPrevious()) {
        qDebug() << "iterator it has previous!";
    } else {
        qDebug() << "iterator it hasn't previous!";
    }
    QMutableListIterator<QString> itMutable(list);
    itMutable.toFront();
    while (itMutable.hasNext()) {
        if (itMutable.next() == "Third") {
            itMutable.setValue("Value muted!");
        }
    }

    qDebug() << "Const iterator";
    it.toFront();
    while (it.hasNext()) {
        qDebug() << "Element : " << it.next();
        /// Странно, но если mutable итератор изменяет значение
        /// то после изменения const итератор сохраняет значениие
        /// "First", "Second", "Third"
    }

    qDebug() << "Mutable iterator";
    itMutable.toFront();
    itMutable.next();
    itMutable.remove(); /// "Second", "Value Muted!"
    itMutable.toBack();
    itMutable.insert("First");
    itMutable.toFront();
    while (itMutable.hasNext()) {
        qDebug() << "Element : " << itMutable.next();
        /// "Second", "Value Muted!", "First"
    }
    ///          pv1Begin [v1] pv1End = pv2begin [v2] pv2End ... pvnBegin [vN] pvnEnd
    ///   ^ toFront();     ^ toFront()+next()                                           ^ toBack();
    /// Быть осторожным с toFront()+ value()  и toBack()+ value()
    /// Ассерт кричит
    return a.exec();
}
