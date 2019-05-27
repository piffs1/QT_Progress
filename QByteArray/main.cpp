#include <QCoreApplication>
#include <QByteArray>
#include <QDebug>

/// QByteArray очень похож на QVector<T>
/// Допускается хранения элементов размером 1 байт

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray arr;
    arr.reserve(3);
    arr[0] = arr[1] = 0xFF;
    arr[2] = 0x0;
    QByteArray c = "Test Data";
    QByteArray aCompressed = qCompress(c);
    qDebug() << aCompressed; /// \00\xxx etc..
    qDebug() << qUncompress(aCompressed); /// "Test Data"

    qDebug() << c.toBase64();   /// VGV...
    qDebug() << c.fromBase64(c.toBase64()); /// "Test Data"

    return a.exec();
}
