#include <QCoreApplication>
#include <QDebug>
#include <QBitArray>

/// Битовый aka Булевый массив
/// Каждое значение хранит (1 бит???) не расходуя лишней памяти
///

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBitArray bits(3);

    bits[0] = bits[1] = false;
    bits[2] = true;
    /// testBit() read
    /// setBit() write

    return a.exec();
}
