#include "calender.h"
#include "holders.h"
#include "timeslot.h"
#include "timetable.h"
#include "stylist.h"
#include <QString>
#include "holders.h"
#include <QVector>
// Create the vector of each day so there is a vector or time tables, to create a week
void Calenders::CreateTimetableVector(Holders holderobj, int chairnum)
{

    QVector<Timetable> timetabler;
   // Timetablevector.reserve(14); // DO WE NEED TO  ASSIGN  SIZE 14 IN  HEADER?
    QVector<Timetable>::Iterator first = timetabler.begin(), toofar = timetabler.end(), cur;
    int count = 0;
    cur = first;
    while(cur != toofar)
       { cur->SetTimetableNumber(count);
         cur->CreateSlotVector(chairnum);
        ++cur;
    }
    count++;
    Timetablevector = timetabler;

}

QVector<Timetable> Calenders::getTimetableVector() const
{
    return Timetablevector;
}

void Calenders::BookAStylist(stylist booking, Holders data, Calenders cal)
{
    // for the stylist, get their availability vector and iterate
    // through it
    for(int i = 0; i<booking.GetVectorOfAvailability().length(); i++)
    {
       // for(int p = 0; p<Timetablevector.length(); p++)
        //{ IS THIS LOOP NEEDED!!

            if(booking.GetVectorOfAvailability().at(i) == "Monday")
            {
                // for the length of the number of hours listed in the
                // FIRST vector of the vector of hours, as this
                // is the vector corresponding to Monday's hours
                for(int z = 0; z<booking.GetVectorOfHours().at(1).length();z++)
                {
                    cal.getTimetableVector()[1].getTimeslotVector()[booking.GetVectorOfHours()[1][z]].BookChair(booking,cal.getTimetableVector()[1].getTimeslotVector()[booking.GetVectorOfHours()[1][z]]);;
                    cal.getTimetableVector()[8].getTimeslotVector()[booking.GetVectorOfHours()[1][z]].BookChair(booking,cal.getTimetableVector()[8].getTimeslotVector()[booking.GetVectorOfHours()[1][z]]);;
                   // cal.getTimetableVector().at(1).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                    //cal.getTimetableVector().at(8).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                }
            }
            if(booking.GetVectorOfAvailability().at(i) == "Tuesday")
            {
                for(int z = 0; z<booking.GetVectorOfHours().at(2).length();z++)
                {
                    cal.getTimetableVector()[2].getTimeslotVector()[booking.GetVectorOfHours()[2][z]].BookChair(booking,cal.getTimetableVector()[2].getTimeslotVector()[booking.GetVectorOfHours()[2][z]]);;
                    cal.getTimetableVector()[9].getTimeslotVector()[booking.GetVectorOfHours()[2][z]].BookChair(booking,cal.getTimetableVector()[9].getTimeslotVector()[booking.GetVectorOfHours()[2][z]]);;
                 //   cal.getTimetableVector().at(2).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                   // cal.getTimetableVector().at(9).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                }
            }
            if(booking.GetVectorOfAvailability().at(i) == "Wednesday")
            {
                for(int z = 0; z<booking.GetVectorOfHours().at(3).length();z++)
                {
                    cal.getTimetableVector()[3].getTimeslotVector()[booking.GetVectorOfHours()[3][z]].BookChair(booking,cal.getTimetableVector()[3].getTimeslotVector()[booking.GetVectorOfHours()[3][z]]);;
                    cal.getTimetableVector()[10].getTimeslotVector()[booking.GetVectorOfHours()[3][z]].BookChair(booking,cal.getTimetableVector()[10].getTimeslotVector()[booking.GetVectorOfHours()[3][z]]);;

                   // cal.getTimetableVector().at(3).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                    //cal.getTimetableVector().at(10).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                }
            }
            if(booking.GetVectorOfAvailability().at(i) == "Thursday")
            {
                for(int z = 0; z<booking.GetVectorOfHours().at(4).length();z++)
                {
                    cal.getTimetableVector()[4].getTimeslotVector()[booking.GetVectorOfHours()[4][z]].BookChair(booking,cal.getTimetableVector()[4].getTimeslotVector()[booking.GetVectorOfHours()[4][z]]);;
                    cal.getTimetableVector()[11].getTimeslotVector()[booking.GetVectorOfHours()[4][z]].BookChair(booking,cal.getTimetableVector()[11].getTimeslotVector()[booking.GetVectorOfHours()[4][z]]);;
                   // cal.getTimetableVector().at(4).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                    //cal.getTimetableVector().at(11).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                }
            }
            if(booking.GetVectorOfAvailability().at(i) == "Friday")
            {
                for(int z = 0; z<booking.GetVectorOfHours().at(5).length();z++)
                {
                    cal.getTimetableVector()[5].getTimeslotVector()[booking.GetVectorOfHours()[5][z]].BookChair(booking,cal.getTimetableVector()[5].getTimeslotVector()[booking.GetVectorOfHours()[5][z]]);;
                    cal.getTimetableVector()[12].getTimeslotVector()[booking.GetVectorOfHours()[5][z]].BookChair(booking,cal.getTimetableVector()[12].getTimeslotVector()[booking.GetVectorOfHours()[5][z]]);;
                  //  cal.getTimetableVector().at(5).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                    //cal.getTimetableVector().at(12).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                }
            }
            if(booking.GetVectorOfAvailability().at(i) == "Saturday")
            {
                for(int z = 0; z<booking.GetVectorOfHours().at(6).length();z++)
                {
                    cal.getTimetableVector()[6].getTimeslotVector()[booking.GetVectorOfHours()[6][z]].BookChair(booking,cal.getTimetableVector()[6].getTimeslotVector()[booking.GetVectorOfHours()[6][z]]);;
                    cal.getTimetableVector()[13].getTimeslotVector()[booking.GetVectorOfHours()[6][z]].BookChair(booking,cal.getTimetableVector()[13].getTimeslotVector()[booking.GetVectorOfHours()[6][z]]);;
                    //cal.getTimetableVector().at(6).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                    //cal.getTimetableVector().at(13).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                }
            }

            if(booking.GetVectorOfAvailability().at(i) == "Sunday") // WILL NEED TO DECIDE WHAT TO DO WITH SUNDAY
            {
                for(int z = 0; z<booking.GetVectorOfHours().at(6).length();z++)
                {
                    cal.getTimetableVector()[7].getTimeslotVector()[booking.GetVectorOfHours()[7][z]].BookChair(booking,cal.getTimetableVector()[7].getTimeslotVector()[booking.GetVectorOfHours()[7][z]]);;
                    cal.getTimetableVector()[14].getTimeslotVector()[booking.GetVectorOfHours()[7][z]].BookChair(booking,cal.getTimetableVector()[14].getTimeslotVector()[booking.GetVectorOfHours()[7][z]]);;
                    //cal.getTimetableVector().at(6).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                   // cal.getTimetableVector().at(13).getTimeslotVector().at(booking.GetVectorOfHours().at(1).at(z)).BookChair(booking);
                }
            }
    }
}

//QDateTime QDateTime::currentDateTime(); // Does this need to be defined?
