#include "customer.h"
#include <Qstring>

void customer::SetCustomerName(QString z)
{
    Name = z;
}

QString customer::GetCustomerName()
{
    return Name;
}

void customer::SetCustomerService(QString customerservice)
{
    ServiceRequired = customerservice;
}

QString customer::GetCustomerService()
{
    return ServiceRequired;
}

void customer::SetCustomerStylist(QString custstylist)
{
    StylistRequired = custstylist;
}

QString customer::GetCustomerStylist()
{
    return StylistRequired;
}


