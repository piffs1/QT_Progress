#include <QCoreApplication>
#include <QtAlgorithms>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int values[] = {1,1,2,3,4,5};
    const int size = sizeof(values) / sizeof(values[0]);
    int values1[size];
    qCopy(values, values+size, values1); /// equals std::copy
    //qCopyBackward()
    if(*qBinaryFind(values,values+size, 1) != values[size]) {
        qDebug() << "value 1 is founded!"; /// true
        /// Ищет даже с массивами
    }
    /// qBinaryFind в лучшем случае итератор, в худшем = container.end


    int nSize = 0;

    qCount(values, values+size, 1, nSize);
    /// qCount(BeginIter,EndIter, значение, переменная в которую записываем)
    ///
    qDebug() << "nSIZE";
    qDebug() << nSize; /// 2
    qDebug() << "values[1]...";
    for (int i = 0; i < size; i++) {
        qDebug() << values1[i]; /// 1,2,3,4,5
    }
    /// qDeleteAll(beginIt,endIt); /// удаление всех элементов
    /// ремарочка  : для std::vector<IBase*> удобное удаление
    /// вместо for (;;) delete
    /// qEqual сравнение, необходим перегруженный оператор ==
    qDebug() << "=values[1]...";
    qDebug() << *qFind(values, values+size, 3);
    /// qFind возвращает итератор
    /// qFind(begIt,endIt, value)
    /// в худшем случае endIt

    qDebug() << "values[1]...";
    qFill(values1,values1+size,0); /// equals vector.assign(T)
    for (int i = 0; i < size; i++) {
        qDebug() << values1[i]; /// 0, 0, 0, 0, 0
    }
    /// qLowerBound()
    /// qUpperBound()
    /// qSort == std::sort
    /// qStableSort сортировка с сохранением позиций
    /// qSwap()


    return a.exec();
}
