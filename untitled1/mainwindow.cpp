#include "mainwindow.h"     //Header for GUI class
#include "ui_mainwindow.h"  //Header for GUI form
#include <QMessageBox>      //Class for login alert
#include <QWidget>          //Class for widget functions
#include <QApplication>
#include <QString>          //Class for strings
#include <Qfile>            //Class for reading file (fstream)
#include <QTextStream>      //Like stringstream - streams text
#include <QDebug>           //Class for printint to console
#include <vector>           //Includes vector class
#include <QTextEdit>        //Includes class for textboxes
#include <QVectorIterator>
#include <QStringList>

#include "holders.h"
#include "stylist.h"
#include "service.h"
#include "calender.h"



//Global objects
Holders holdersobj;
Calenders calenderobj;



//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);  //Opens on a full screen

    // Sets to page 1 for log in and welcome page
    ui->stackedWidget->setCurrentIndex(1);

    ui->Employee_Info->setVisible(false);


}

//Destructor
MainWindow::~MainWindow()
{
    //Deletes the GUI once the programme ends
    delete ui;
}



//------------------------------//
//----- Navigation Toolbar -----//
//------------------------------//
void MainWindow::on_actionShut_Down_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Do you want to quit?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {

        QApplication::quit();

    } else {
    }
}
void MainWindow::on_actionLog_Off_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_password->setText("");
}
void MainWindow::on_actionMenu_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_actionSetup_triggered()
{

    //******************************************************//
    //******************** Stylist file ********************//
    //******************************************************//

    //Created Arrays to store the widget objects
    QLineEdit *namearray[] = {ui->Name1, ui->Name2, ui->Name3, ui->Name4, ui->Name5, ui->Name6, ui->Name7, ui->Name8, ui->Name9, ui->Name10};    
    QLineEdit *surnamearray[] = {ui->Surname1, ui->Surname2, ui->Surname3, ui->Surname4, ui->Surname5, ui->Surname6, ui->Surname7, ui->Surname8, ui->Surname9, ui->Surname10};
    QLineEdit *Phonearray[] = {ui->Phone_No1, ui->Phone_No2, ui->Phone_No3, ui->Phone_No4, ui->Phone_No5, ui->Phone_No6, ui->Phone_No7, ui->Phone_No8, ui->Phone_No9, ui->Phone_No10};
    QTextEdit *TextBoxArray[] = {ui->TextBox1, ui->TextBox2, ui->TextBox3, ui->TextBox4, ui->TextBox5, ui->TextBox6, ui->TextBox7, ui->TextBox8, ui->TextBox9, ui->TextBox10};
    QComboBox *ComboArray[] = {ui->comboBox1, ui->comboBox2, ui->comboBox3, ui->comboBox4, ui->comboBox5, ui->comboBox6, ui->comboBox7, ui->comboBox8, ui->comboBox9, ui->comboBox10};

    //Declared variables & string list
    QString Line, Name, Surname, Telephone_No, Service, Check, employment, s_starttime, s_finishtime, shift, seperate;
    int starttime, finishtime;
    QStringList Pieces, Parts, chunk;

    //Opens file
    QFile file ("C:/Users/patri/Desktop/sophie/Management2.txt");

    //Checks if it can be opened - if not print following
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
          qDebug() << "Could not open file for reading";
       return;
    }

    //Counters for cycling through alternate lines in text file seperately
    int Datacounter = 0, Shiftcounter = 0;

    //For loop till end of file
    for (int rows = 0; !file.atEnd(); rows++){

        //Streams the data from the file
        QTextStream Stream (&file);

        Line = file.readLine();    //Reads line of text
        Pieces = Line.split(";");  //Splits line up seperated by ;

        Check = Pieces[0]; //Stores element 1 of each line in "Check" to carry out initial check

        if (Check != "Avaliability"){   //If data line

            Name = Pieces[0];                    //Stores element 0 of string list in name
            Surname = Pieces[1];                 //Stores element 1 of string list in surname
            Telephone_No = Pieces[2];            //Stores element 2 of string list in Telephone_No
            employment = Pieces[3];              //Stores element 3 of string list in employment

            namearray[Datacounter]->setText(Name);         //Sets current namearray element to current name
            surnamearray[Datacounter]->setText(Surname);   //Sets current surnamearray element to current surname
            Phonearray[Datacounter]->setText(Telephone_No);//Sets current phonearray element to current Telephone_No
            ComboArray[Datacounter]->addItem(employment);  //Sets current ComboArray element to current employment

            int numofservices = 0; //Variable to count number of services

            //For loop till end of the line
            for (int Columns = 4; Columns < Pieces.length(); Columns++){

                Service = Pieces[Columns];                         //Stores element current element in Service
                TextBoxArray[Datacounter]->append(Service);        //Appends current TextBoxarray element with Service
                numofservices++;                                   //Increment numofservices
            }
            Datacounter++;  //Increments datacounter to count stylist lines in text file

            //Adds stylist information to vector in holders
            holdersobj.AppendToStylistVector(Name, Surname, Telephone_No, numofservices);

        }
        else {      //else if avaliability line
            for (int j = 1; j < Pieces.length(); j++){

                ComboArray[Shiftcounter]->addItem(Pieces[j]);  //Stores avaliability into comboarray

                seperate = Pieces[j];           //Stores Pieces[j] in QString seperate
                Parts = seperate.split(":");    //Splits up QString seperate by ":"
                QString day = Parts[0];         //Stores the day in QString day

                if (day == "OFF"){         //Checks if shift == "OFF"
                    shift = Parts[1];           //If == "OFF", store in QString shift
                }
                else{                           //Else...
                    s_starttime = Parts[1];     //Stores the starting time in QString starting time
                    QString middle = Parts[2];  //Stores rest of shift in QString middle
                    chunk = middle.split("-");  //Splits middle by "-"
                    s_finishtime = chunk[1];    //Takes chunk[1] as finish time
                }

                bool ok;
                int i_starttime = s_starttime.toInt(&ok, 10);   //Converts start time to int
                int i_finishtime = s_finishtime.toInt(&ok, 10); //Converts finish time to int

                int Hours = ((i_finishtime - i_starttime)*2);   //Calculates amount of timeslots per shift





                
                

            }
           Shiftcounter++;  //Incrments shiftcounter to count avaliability lines in text file
        }
     }//FILE//
    file.close();
//***************************************************************************//


    //******************************************************//
    //******************** SERVICE FILE ********************//
    //******************************************************//

    QFile file2 ("C:/Users/patri/Desktop/sophie/services.txt");
    QString Line2, servicenamefile,servicelengthfile,servicecostfile;
    QStringList Pieces2;

    //Checks if it can be opened - if not print following
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
          qDebug() << "Could not open file for reading";
       return;
    }

    for (int rows = 0; !file2.atEnd(); rows++){

        QTextStream Stream (&file2); //Streams the data from the file

        Line2 = file2.readLine();    //Reads line of text
        Pieces2 = Line2.split(";");  //Splits line up seperated by ;

        bool ok;
        servicenamefile = Pieces2[0];   //Stores service name in servicenamefile
        servicelengthfile = Pieces2[1]; //Stores service length in servicelengthfile
        servicecostfile = Pieces2[2];   //Stores service cost in servicecostfile

        int serlength = servicelengthfile.toInt(&ok, 10);   //Converts service length to integer
        float sercost = servicecostfile.toFloat();          //Converts service cost to float

        holdersobj.AppendToServiceVector(servicenamefile, serlength, sercost);  //Appends service vector with each service
    }
    file2.close();
    //**********************************************************//


    //Possibly read in chair number
    //int chairnum = 5;
    //calenderobj.CreateTimetableVector(holdersobj, chairnum);


    ui->Employee_Info->setVisible(true);
    ui->actionSetup->setDisabled(true);

}

//------------------------------//
//--------- Login Page ---------//
//------------------------------//
void MainWindow::on_Log_In_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username != "Martin" && password == "Test"){
        QMessageBox::warning(this, "Login", "Username is incorrect");
    }
    else if (username == "Martin" && password != "Test"){
        QMessageBox::warning(this, "Login", "Password is Incorrect");
    }
    else if (username == "Martin" && password == "Test"){
        QMessageBox::information(this, "Login", "Sign in successfull");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if (username != "Martin" && password != "Test"){
        QMessageBox::warning(this, "Login", "Username and Password is Incorrect");
    }
}

//------------------------------//
//------------- Menu -----------//
//------------------------------//
void MainWindow::on_Booking_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
void MainWindow::on_Employee_Info_clicked()
{
   ui->stackedWidget->setCurrentIndex(3);

}


//------------------------------//
//------- Choose Consumer ------//
//------------------------------//
void MainWindow::on_Stylist_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


//------------------------------//
//---------- Days Page ---------//
//------------------------------//
void MainWindow::on_Previous_Date_clicked()
{

}
void MainWindow::on_Next_Day_clicked()
{

}
void MainWindow::on_Monday_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_Tuesday_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_Wednesday_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_Thursday_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_Friday_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_Saturday_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}





void MainWindow::on_Finances_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);


}

void MainWindow::on_PredictFinances_clicked()
{
    // !!!!!!!!!    !!!!!!  !!!!!!    !!!!!!!!
        // ADD TO  SET UP, WHEN SET UP CLICKED, CALL CALCULATE PREDICTED INCOME!!!!!!
     //   float PredictedIncomeforMon, PredictedIncomeforTue, PredictedIncomeforWed, PredictedIncomeforThur;
       // float PredictedIncomeforFri, PredictedIncomeforSat;
        //Calenders calenderobj;
        //QVector<Timetable> Calendervect = calenderobj.getTimetableVector();
        //PredictedIncomeforMon = Calendervect[0].GetPredictedIncome();
        //PredictedIncomeforTue = Calendervect[1].GetPredictedIncome();
        //PredictedIncomeforWed = Calendervect[2].GetPredictedIncome();
        //PredictedIncomeforThur = Calendervect[3].GetPredictedIncome();
        //PredictedIncomeforFri = Calendervect[4].GetPredictedIncome();
        //PredictedIncomeforSat = Calendervect[5].GetPredictedIncome(); // HOW TO OUTPUT NUMBERS???

    ui->lineEditMon->setText("The predicted income for Monday is: ");
    ui->lineEdit_Tue->setText("The Predicted income for Tuesday: ");
    ui->lineEditWed->setText("The predicted incomefor Wednesday is: ");
    ui->lineEditThu->setText("The Predicted income for Thursday: ");
    ui->lineEditFri->setText("The Predicted income for Friday: ");
    ui->lineEditSat->setText("The Predicted income for Saturday: ");

}




