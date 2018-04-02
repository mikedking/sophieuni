#include "service.h"
#include "holders.h"
#include <Qstring>
#include <QVector>

void service::SetNumberOfServices(int a)
{
    NumberOfServices = a;
}

int service::GetNumberOfServices()
{
    return NumberOfServices;
}

void service::SetService(QString b)
{
    ServiceName = b;
}

QString service::GetService() const
{
    return ServiceName;
}

void service::SetServiceCost(float c)
{
    ServiceCost = c;
}

float service::GetServiceCost() const
{
    return ServiceCost;
}

void service::SetServiceLength(int d)
{
    Servicelength = d;
}

int service::GetServiceLength() const
{
    return Servicelength;
}


// TO BE USED WHEN ADDING SERVICES,
// TAKES IN THE SERVICE NAME, IF IT IS THE SAME
// AS ONE IN THE ARRAY OF SERVICES THEN IT WILL BE RETURNED,
// AND DOESN'T NEED TO BE ADDED, OTHERWISE IT WILL BE APPENDED
// TO THE VECTOR
// SHOULD BE CALLED AND ITERATE THROUGH THE VECTOR, COMPARING
// EACH SERVICE NAME IN THE VECTOR WITH THE SERVICE NAME TAKEN
// IN


/*service const* service::Serviceself(QString e) const
{
    if(strcmp(this->GetService().c_str(),e.c_str())==0)
    {
        return this;
    }
    else
    {
        // OR APPEND TO THE VECTOR WHICH IS IN THE HOLDER CLASS
        // AND SO THE HOLDER OBJECT WILL BE GENERATED WHEN THE DAY IS
        // CREATED, SO THE OBJECT WILL BE CREATED, THEN
        // SERVICEVECTOR.APPEND(THIS);

        return NULL;
    }

} */
