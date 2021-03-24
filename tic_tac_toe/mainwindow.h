#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setPalya();
    int nyert(int m[][3]);
    bool dontetlen(int m[][3]);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
