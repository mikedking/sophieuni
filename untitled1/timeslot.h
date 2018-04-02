#ifndef TIMESLOT_H
#define TIMESLOT_H

#include "stylist.h"
#include "customer.h"
#include "chairs.h"
#include <QString>
#include <QVector>

class Timeslot
{
public:

    // So the number of chairs in the array can be known
    // WILL FIRST BE DECLARED IN TIMETABLE CLASS FOR EACH
    // TIMESLOT ELEMENT IN THE VECTOR
    void SetNumberOfChairsInslot(int chairnums);
    int GetNumberOfChairsInslot();

    void CreateVectorOfChairs();
    QVector<Chairs> GetChairVector();

    // stylist who wants to book a chair and the chair they want
    void BookChair(stylist, Timeslot);
    // this takes in  a stylist and assigns it to one of the chairs. When
    // this chair in the array of chairs is called, the chair function SetStylist
    // is used and the stylist is assigned to that chair

    // customer who wants to book a chair and the chair they want
    void BookForCustomer(customer, int, Timeslot);
    // takes in a customer and assigns it to specified chair (((MAYBE THE CREATEARRAYOFCHAIRS
    // FUNCTION COULD BE CALLED WHEN EACH TIMESLOT IS MADE, SO WHEN THE GUI PAGE OF THE
    // ARRAY OF CHAIRS IN EACH TIMESLOT IS DISPLAY, EACH CHAIR ALREADY HAS IT'S NUMBER, AND BY
    // CLICKING ON IT YOU CHOOSE THAT NUMBER)))
    // when this chair in the array of chairs is called, the OVERLOADED chair function  SetStylist
    // takes in the customer object and assgins it to the chair.

    stylist GetChairStylist(int, Timeslot); // asks for the chair and returns the stylist there
    customer GetChairCustomer(int, Timeslot); // asks for the chair and returns the customer there
    void SetTimeslotNumber(int); // Sets the time slot number, is called n Timetable in the
                                 // CreateSlotVector function
    int GetTimeslotNumber();

    // WILL NEED TO CONSIDER WHERE TO CALL THIS FUNCTION SO THAT THE TIME SLOT IS KNOWN, CAN'T
    // TAKE IN THE TIMESLOT TO BE CANCELLED HERE AS A VAIRABLE AS IT IS ALREADY IN THE TIMESLOT
    // OBJECT, THE TIME SLOT NUMBER NEEDS TO BE KNOWN TO GET TO THIS POINT.



    //void CancelAppointment(customer, int); //takes in customer name and the chair



    void Walk_in(customer, int);
private:
    QVector<Chairs> chairvector;
    int NumberofchairsInTimeSlot;
    int TimeslotNumber; //Each time slot is assigned a number, 9:00 to 9:30 is timeslot 1,
                        // 9:30 to 10:00 is timeslot 2, etc.

};

#endif
