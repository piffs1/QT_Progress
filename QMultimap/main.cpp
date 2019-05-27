#include <QCoreApplication>
#include <QMultiMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMultiMap<QString, QString> mapPhonebook;
    mapPhonebook.insert("Boris", "88888888");
    mapPhonebook.insert("Boris", "77777777");
    mapPhonebook.insert("Boris", "66666666");
    mapPhonebook.insert("Boris", "55555555");
    mapPhonebook.insert("Host", "127.0.0.1");
    for(auto it = mapPhonebook.find("Boris");
        it != mapPhonebook.end() && it.key() == "Boris"; ++it)
    {
        qDebug() << it.value(); /// "55555555", "66666666", "77777777", "88888888"
    }

    for (
         QMultiMap<QString,QString>::iterator it = mapPhonebook.begin();
         it !=mapPhonebook.end();
         ++it)
    {
        /// FULL DEBUG
        qDebug() << "Key : " << it.key() << " Value : " << it.value();
    }

    return a.exec();
}
