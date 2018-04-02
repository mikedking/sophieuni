#ifndef TIMETABLE_H
#define TIMETABLE_H
// DO YOU NEED TO INCLUDE VECTOR
// LIBRARY IN THIS
#include "timeslot.h"
#include <QVector>

class Timetable
{
public:
    void CreateSlotVector(int);
    QVector<Timeslot> getTimeslotVector() const;
    void SetTimetableNumber(int);
    int GetTimeTableNumber();
    void CalcPredictedIncome(int);
    float GetPredictedIncome();
//    void CalcNumberOfBookedChairs(QVector<Timeslot>);
//    int GetNumberOfTimeBookedChairs();
private:
    QVector<Timeslot> Timeslotvector;
    int TimetableNumber;
    float PredictedIncomeforday;
    float ActualIncomeforday;
  //  int NumberOfChairsForDay;
};


#endif // TIMETABLE_H
