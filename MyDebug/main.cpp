#include <QCoreApplication>
#include <QDebug>
void msgToFile(QtMsgType type, const QMessageLogContext &context, const QString& msg)
{
    switch (type) {
    case QtDebugMsg:
        break;
    case QtWarningMsg:
        break;
    case QtCriticalMsg:
        break;
    case QtFatalMsg:
        break;

    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int n = 7777;
    qDebug() << "DEC :" << n << " Hex :" << hex << uppercasedigits << n; ///DEC 7777 HEX 1E61
    qDebug().nospace() << 1 << "1" << "1"; /// 111
    return a.exec();
}
