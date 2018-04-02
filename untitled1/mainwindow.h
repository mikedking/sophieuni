#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QMainWindow - a pre-defined base class that contains necessary elements to create
//a main window, toolbar or status bar etc.
//QMAinWindow also inherits from QWidget and many other extensions.
#include <QMainWindow>

//Uses namespace ui for class MainWindow.
namespace Ui {
class MainWindow;
}

//Creates a class called MainWindow that inherited from QMainWindow base class
class MainWindow : public QMainWindow
{
    //A Meta-Object Compiler (MOC) - handles Qt C++ extension files
    //Any class that has this macro, tells the system that this class must be compiled using a MOC
    //Any class that has a GUI must be compiled using a MOC and not a standard compiler
    //MOC is also required for signals and slot mechanisms.
    Q_OBJECT

public:
    //Constructor that creates a MainWindow Object.
    explicit MainWindow(QWidget *parent = 0);

    //Destructor
    ~MainWindow();

    //Initialises stylists, chairs and services
    void setup();


private:
    //MainWindow object called *ui
    Ui::MainWindow *ui;

//Slots and signals are a way to communicated between objects
//EG - If we press a button, we want other buttons/labels (widgets) to react to the buttom press.
private slots:

    //------------------------------//
    //----- Navigation Toolbar -----//
    //------------------------------//
  //  void on_Shut_Down_clicked();
    //void on_Log_Off_clicked();
    //void on_Menu_clicked();

    //------------------------------//
    //--------- Login Page ---------//
    //------------------------------//
    void on_Log_In_clicked();

    //------------------------------//
    //------------- Menu -----------//
    //------------------------------//
    void on_Booking_clicked();

    //------------------------------//
    //---------- Days Page ---------//
    //------------------------------//
    void on_Next_Day_clicked();
    void on_Previous_Date_clicked();
    void on_Monday_clicked();
    void on_Tuesday_clicked();
    void on_Wednesday_clicked();
    void on_Thursday_clicked();
    void on_Friday_clicked();
    void on_Saturday_clicked();




    void on_Stylist_clicked();
    void on_Employee_Info_clicked();
//    void on_Set_Up_clicked();
    void on_Finances_clicked();
    void on_PredictFinances_clicked();
    void on_actionShut_Down_triggered();
    void on_actionLog_Off_triggered();
    void on_actionMenu_triggered();
    void on_actionSetup_triggered();
};
#endif // MAINWINDOW_H
