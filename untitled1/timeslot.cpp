#include "timeslot.h"
#include "stylist.h"
#include "customer.h"
#include "chairs.h"
#include <QString>
#include <QVector>

void Timeslot::CreateVectorOfChairs()
{
    // CREATE THE ARRAY OF CHAIRS AND ASSIGN
    // EACH CHAIR A NUMBER SO EACH CHAIR CAN BE
    // CALLED AND RECOGNISED

        QVector<Chairs> chairvec;
        QVector<Chairs>::Iterator first = chairvec.begin(), toofar = chairvec.end(), cur;
        cur = first;
        int i = 0;
        while(cur != toofar)
           {
            cur->SetChairNumber(i);
        }
        chairvector = chairvec;

}

QVector<Chairs> Timeslot::GetChairVector()
{
    return chairvector;
}

void Timeslot::BookChair(stylist styler,Timeslot obj)
{
    for(int i; i<NumberofchairsInTimeSlot; i++)
    {
        if(obj.GetChairVector()[i].GetStylist().GetStylistName() == "")
        {
            obj.GetChairVector()[i].SetStylist(styler);
            break;
        }
        else
        {
            continue; // not sure if this is necessary?
        }

    }
}

void Timeslot::BookForCustomer(customer cust, int Chairwanted,Timeslot obj)
{
    obj.GetChairVector()[(Chairwanted)].SetCustomer(cust);
}

stylist Timeslot::GetChairStylist(int Chairof, Timeslot obj)
{

    stylist Answer = obj.GetChairVector()[(Chairof)].GetStylist();

    return Answer;
}

customer Timeslot::GetChairCustomer(int ChairofCust, Timeslot obj)
{

    customer chaircust = obj.GetChairVector()[ChairofCust].GetCustomer();
    return chaircust;
}
void Timeslot::SetNumberOfChairsInslot(int numChair)
{
    NumberofchairsInTimeSlot = numChair;
}

int Timeslot::GetNumberOfChairsInslot()
{
    return NumberofchairsInTimeSlot;
}
void Timeslot::SetTimeslotNumber(int timenum)
{
    TimeslotNumber = timenum;
}

int Timeslot::GetTimeslotNumber()
{
    return TimeslotNumber;
}

// clears all current values in the appointment

/*
void Timeslot::CancelAppointment(customer Cancel, int chairremove)
{
    GetChairArray().
    chairarray[chairremove].Customerobj.SetCustomerName("");
    chairarray[chairremove].Customerobj.SetCustomerService("");
    chairarray[chairremove].Customerobj.SetCustomerService("");
}
*/

/*
void Timeslot::Walk_in(customer walkin, int current) // current is current time or timeslot number
{

}
*/
