#include <QCoreApplication>
#include <QObject>
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QObject *pobj1 = new QObject;
    QObject *pobj2 = new QObject(pobj1);
    QObject *pobj3 = new QObject(pobj2);
    QObject *pobj4 = new QObject(pobj1);

    pobj2->setObjectName("The first child of pobj1");
    pobj4->setObjectName("The second child of pobj1");
    pobj3->setObjectName("The first child of pobj2");

    for (QObject* pobj = pobj3; pobj->parent()!= nullptr; pobj = pobj->parent())
    {
        qDebug() << pobj->objectName(); // OK
    }

    QObject* pobj = pobj1->findChild<QObject*>("The first child of pobj2");
    qDebug() << pobj->objectName(); // OK
    // Отличие findChild от findChildren, findChild возвращает указатель, findChildren список указателей
    QList<QObject*> pList1 = pobj1->findChildren<QObject*>();
    for(auto it = pList1.begin(); it!=pList1.end(); ++it) // OK вернет всех детишек
        qDebug() << *it;
    pobj1->dumpObjectInfo();
    pobj1->dumpObjectTree();    // Дерево дебагается только вниз
    qDebug() << pobj2->metaObject()->className(); // QObject
    // pobj->inherits("QObject"); // true если сам аргумент это сам класс или его потомок
    return a.exec();
}
