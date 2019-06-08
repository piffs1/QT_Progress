#include <QCoreApplication>
#include <QtWidgets>
#include "syntaxhighlighter.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextEdit txt;

    QFont fnt("Lucida Console", 9, QFont::Normal);
    txt.document()->setDefaultFont(fnt);

    new SyntaxHighlighter(txt.document());

    QPalette pal = txt.palette();
    pal.setColor(QPalette::Base, Qt::darkBlue);
    pal.setColor(QPalette::Text, Qt::yellow);
    txt.setPalette(pal);

    txt.show();
    txt.resize(640,480);

    QFile file(":/syntaxhighlighter.cpp");
    file.open(QFile::ReadOnly);
    txt.setPlainText(QLatin1String(file.readAll()));

    return a.exec();
}
