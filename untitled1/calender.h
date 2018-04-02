#ifndef CALENDER_H
#define CALENDER_H

#include "timeslot.h"
#include "timetable.h"
#include <QString>
#include <QDate>
#include <QDateTime>
#include "holders.h"
#include "stylist.h"
#include <QVector>

// TO CREATE THE VECTOR OF TIMETABLE DAYS, CREATING A WEEK(S)
class Calenders
{

private:
   // int currentdate; // Not sure if necessary
    QVector<Timetable> Timetablevector;

public:
    Calenders(){}
    void CreateTimetableVector(Holders,int);
    QVector<Timetable> getTimetableVector() const;



    void BookAStylist(stylist, Holders, Calenders);


  //  QDateTime QDateTime::currentDateTime(); //returns current date NOT SURE HOW TO TEST TO SEE WHAT THE OUT
                                            //PUT IS

};

#endif // CALENDER_H
