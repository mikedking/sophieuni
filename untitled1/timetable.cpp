#include "timetable.h"
#include "timeslot.h"
#include <QString>
#include <QVector>
#include <QDebug>


// Class to create a vector of all the time slots.
// Each slot represents a time e.g. 9:00 to 9:30, but they will
// just be represented with an integer, so 9:00 to 9:30 is slot 1
void Timetable::CreateSlotVector(int Numberofchairs)
{
    QVector<Timeslot> theTimeslotvector(16);
    QVector<Timeslot>::Iterator first = theTimeslotvector.begin(), toofar = theTimeslotvector.end(), cur;

    // TAKE IN FROM FILE HOW MANY CHAIRS ARE IN EACH TIME SLOT

    int i = 0;
    cur = first;
    while(cur!=toofar)
    {
        cur->SetTimeslotNumber(i);
        cur->SetNumberOfChairsInslot(Numberofchairs);
        cur->CreateVectorOfChairs();
        i++;
        ++cur;
        // so now every time slot has been created, and the vector of chairs in each has
    }
    Timeslotvector = theTimeslotvector;


}


QVector<Timeslot> Timetable::getTimeslotVector() const
{
    return Timeslotvector;
}

void Timetable::SetTimetableNumber(int timenum)
{
    TimetableNumber = timenum;
}

int Timetable::GetTimeTableNumber()
{
    return TimetableNumber;
}


// NEW ADDED IN FUNCTION
// !!!!!!!!!!!!!!
void Timetable::CalcPredictedIncome(int NumOfChairs)
{
  float TotalCostOfServices = 0;
  float AverageCostofServices;
      QVector<service> servicevector;
   // Begin iterating through the services
      // MAYBE CREATE OBJECT OF HOLDER, WHICH COULD BE SET UP IN MAIN WHEN THE
      // GUI IS CREATED, AND USE IT IN HERE, TO ASSIGN THE SERVICE VECTOR TO HERE TO
      // USE  TO CALCULATE PREDICTED INCOME
      int count = 0;
        QVector<service>::Iterator first = servicevector.begin(), toofar = servicevector.end(), cur;
        cur = first;
        while(cur != toofar)
           {
            float currentcost = cur->GetServiceCost();
            TotalCostOfServices = (TotalCostOfServices + currentcost);
            ++cur;
            ++count;
        }
        AverageCostofServices = TotalCostOfServices/count;
        PredictedIncomeforday = AverageCostofServices*NumOfChairs;
}

// NEW ADDED IN  FUNCTION !!!!!!!1
float Timetable::GetPredictedIncome()
{
    return PredictedIncomeforday;
}


// NEW ADDED  IN  FUNCTION  !!!!!!!1
// TAKE IN THE VECTOR OF TIMESLOTS
//void Timetable::CalcNumberOfBookedChairs(QVector<Timeslot> Timeslotvectors)
//{
//    //QVector<Timeslot> Timeslotvector;
//    QVector<Timeslot>::Iterator first = Timeslotvectors.begin(), toofar = Timeslotvectors.end(), cur;
//    cur = first;
//    int count = 0; // number of booked chairs
//    while(cur!=toofar)
//    {

//       for(int i = 0; i<cur->GetNumberOfChairsInslot(); i++)
//       {
//           if((cur->GetChairArray()[i].GetCustomer().GetCustomerName())!= "")
//           {
//               count = count + 1;
//           }
//       }
//       ++cur;

//    }
//    NumberOfChairsForDay = count;


//}

//int Timetable::GetNumberOfTimeBookedChairs()
//{
//    return NumberOfChairsForDay;
//}
