#include "chairs.h"
#include "stylist.h"
#include "customer.h"
#include <QString>

void Chairs::SetStylist(stylist styler)
{
   Stylistobj =  styler;
}

stylist Chairs::GetStylist()
{
    return Stylistobj;
}
void Chairs::SetCustomer(customer custom)
{
    Customerobj = custom;
}

customer Chairs::GetCustomer()
{
    return Customerobj;
}

void Chairs::SetChairNumber(int chairnum)
{
    ChairNumber = chairnum;
}

int Chairs::GetChairNumber()
{
    return ChairNumber;
}
