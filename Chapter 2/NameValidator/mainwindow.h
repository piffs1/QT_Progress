#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>
class NameValidator : public QValidator {
public:
    NameValidator(QObject * parent) : QValidator(parent)
    {
    }

    virtual State validate(QString &str, int &nPos) const
    {
        QRegExp rxp = QRegExp("[0-9]");
        if (str.contains(rxp)) {
            return Invalid;
        }
        return Acceptable;
    }
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    NameValidator* m_pnameValidator;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
