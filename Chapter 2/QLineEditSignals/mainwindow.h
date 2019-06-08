#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setSignalTextChanged(const QString& msg);
    void setSignalCursorPositionChanged(int arg1, int arg2);
    void setSignalEditingFinished();
    void setSignalReturnPressed();
    void setSignalSelectionChanged();
    void setSignalTextEdited(const QString& msg);

private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
