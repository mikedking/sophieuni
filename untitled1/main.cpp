#include "mainwindow.h"

//QApplication class contains exec() function
#include <QApplication>

//Main
int main(int argc, char *argv[])
{
    //Creates object of QApplication class
    QApplication a(argc, argv);

    //Creates object of MainWindow
    MainWindow w;

    //Executes show() function from QWidget, inherited by QMainWindow
    //Then inherited by MainWindow from QMainWindow.
    //Widget function to show mainwindow.
    w.show();

    //Exec() function runs the event loop and essentially powers the GUI.
    //Without an events loop, the GUI and all it's buttons would be unresponsive.
    return a.exec();
}
