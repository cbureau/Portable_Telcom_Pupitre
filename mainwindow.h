#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <androidrfcomm.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    AndroidRfComm *rfcomm;
};

#endif // MAINWINDOW_H
