#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QRegExp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str1 = "";
    QString str2;

    qDebug() << str1.isNull(); /// false
    qDebug() << str2.isNull(); /// true

    qDebug() << str1.isEmpty(); /// true
    qDebug() << str2.isEmpty(); /// true

    str1 = "Bo";
    str2 = "ris krutoi dog";

    str1.append(str2); /// "Boris krutoi dog"
    str1.replace("dog","cat"); /// Boris krutoi cat

    str1.toUpper(); /// BORIS KRUTOI CAT
    str1.toLower(); /// boris krutoi cat

    str1 = str1 + ". Emu "+ QString::number(1) + " godika"; /// "Boris krutoi cat. Emu 1 godika"

    qDebug() << str1;

    QString str3;

    QTextStream(&str3) << "Mne skoro " << 22 << ". Strashno."; /// "Mne skoro 22. Strashno."
    qDebug() << str3;

    bool ok = false;
    QString str4 = "234.5";

    double dbl = str4.toDouble(&ok); /// ok = true
    int n = str4.toInt(&ok); /// ok = false;
    /// QString::to(Int|Double|Short|etc...)
    /// toInt(bool*) в случае успеха bool* true

    QString strSentence = "Boriska lubit myasko a ya ego!";
    QStringList strList = strSentence.split(" "); /// "Boriska", "lubit", "myasko", "a", "ya" ,"ego!"

    strSentence = strList.join("+"); /// "Boriska+lubit+myasko+a+ya+ego!";

    strSentence.endsWith("ego!"); /// true
    strSentence.startsWith("boriska",Qt::CaseInsensitive); /// true

    strSentence.contains("MyASKo", Qt::CaseInsensitive); /// true


    /// QString::indexOf(Q)
    /// Поиск первого вхождения в строку,
    /// в худшем случае -1

    /// QString::lastIndexOf(Q)
    /// Поиск последнего вхождения в строку,
    /// в худшем случае -1

    /// QString::left(int)
    /// "Boris".left(4) == "Bori"
    /// Возвращает строку от 0 до int

    /// QString("Boris").right(3); /// == "ris"
    /// Если аргумент > QString.size() выводит строку полностью

    /// QString("Boriska norm pacan").mid(8,4) == "norm"
    /// mid(position, len) с position до position+len, если не указывать размер,
    /// или указывать его больше размера строки, выведется строка до конца.

    /// QString("500 DNEI   BEZ   EZHE.....").simplified(); /// "500 DNEI BEZ EZHE....."
    /// Удаляет лишние пробелы.




    return a.exec();
}
