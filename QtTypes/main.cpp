#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()  << "Number of bytes for qint64 = " << sizeof(qint64); // qlonglong, long long
    qDebug()  << "Number of bytes for qint32 = " << sizeof(qint32); // int
    qDebug()  << "Number of bytes for qint16 = " << sizeof(qint16); // short
    qDebug()  << "Number of bytes for qint8 = " << sizeof(qint8);   // char
    //quint8 unsigned char etc..
    qDebug() << "Minimum of qint64 = -" << ~(~quint64(0)>>1);
    qDebug() << "Maximum of qint64 = " << (~quint64(0)>>1);

    return a.exec();
}
