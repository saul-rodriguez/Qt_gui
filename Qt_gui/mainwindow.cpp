#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <wiringPi.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    state = 0;
    num = 0;

    setupPins(); //Initialize pins
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ToggleButton_clicked()
{
    qDebug("Button pressed");

    if (state) {
        state = 0;
         digitalWrite(17, LOW);
    } else {
        state = 1;
        digitalWrite(17, HIGH);
    }

}

void MainWindow::setupPins()
{
    //PIN GPIO.0 as output
    system("gpio mode 0 out"); //mode uses WiringPi pin notation
    system("gpio export 17 out"); //export uses BCM pin notation

    //PIN GPIO.7 as input, pullup resistor activated
    system("gpio mode 7 in");
    system("gpio mode 7 up");
    system("gpio export 4 in");

    //Call WiringPi initialization
    wiringPiSetupSys();

    qDebug("Pins setup finalized");

}

void MainWindow::interrupt()
{
    qDebug("ISR called");

    QString message;
    message.sprintf("Button pressed %d times",num++);
    ui->lineEdit->setText(message);
}
