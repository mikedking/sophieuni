#ifndef CHAIRS_H
#define CHAIRS_H

#include <Qstring>

#include "stylist.h"
#include "customer.h"

class Chairs
{
public:
    // Each chair is assigned a stylist
    void SetStylist(stylist);
    stylist GetStylist();
    // Each chair is assigned a customer
    void SetCustomer(customer);
    customer GetCustomer();

    // Each chair is assigned a number to recognise it.
    // This could be ensure by representing each chair in the
    // GUI and then when you click on one, that one will have a predefined
    // number, and then the stylist and customer can be assigned to it
    // and the chair can be recognised and called later by the number
    // and its positioning on the GUI
    void SetChairNumber(int);
    int GetChairNumber();
private:
    int ChairNumber;
    stylist Stylistobj;
    customer Customerobj;
};

#endif
