#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QTextDocument>
#include <QSyntaxHighlighter>
class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
private:
    QStringList m_strlstKeyWords;
protected:
    enum {NormalState = -1, InsideCStyleComment, InsideCString};
    virtual void highlightBlock(const QString&);
    QString getKeyword(int nPos, const QString& str) const;
public:
    SyntaxHighlighter(QTextDocument* parent = nullptr);
};

#endif // SYNTAXHIGHLIGHTER_H
