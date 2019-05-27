#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <vector>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> vnVec;

    for(int i = 0; i < 6; i++) {
        vnVec.push_back(i);
    }

    qDebug() << vnVec.data();
    /// Возвращение указателя на массив вектора
    /// При получении указателя можно изменять данные
    int *pInt = vnVec.data();
    for(int i = 0; i < 6; i++) {
        /// pInt[i] = 1; /// worked
        qDebug() << pInt[i];    /// 0,1,2,3,4,5
    }


    /// vnVec.fill(value) -> заполнить весь вектор данными value.
    /// vnVec.fill(value,pos) -> заполнить вектор от 0 до pos данными value
    /// std::vector<int> vnSTL = vnVec.toStdVector();   /// OK
    /// QList<int> vnList = vnVec.toList();

    return a.exec();
}
