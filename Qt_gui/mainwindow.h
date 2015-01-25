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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void setupPins();
    void interrupt();

private slots:
    void on_ToggleButton_clicked();

private:
    Ui::MainWindow *ui;

    int state;
    int num;
};

#endif // MAINWINDOW_H
