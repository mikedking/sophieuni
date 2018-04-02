
#include "holders.h"
#include "stylist.h"
#include "customer.h"
#include "service.h"
#include <QString>
#include <vector>
#include <QDebug>

// Customer vector won't take in anything from a file to be preloaded. When a customer wants to book,
// they will enter their details and then their object will be added to the vector
// NEED TO EDIT IT, CREATE A VECTOR, AND THEN APPEND TO IT LATER?
void Holders::CreateVectorOfCustomers(int thesize)
{
    QVector<customer> customervector(thesize);
    QVector<customer>::Iterator first = customervector.begin(), toofar = customervector.end(), cur;
    QString CustomerName,ServiceWanted,Stylistwanted;
    cur = first;
    while(cur != toofar)
       { cur->SetCustomerName(CustomerName);
        cur->SetCustomerService(ServiceWanted);
        cur->SetCustomerStylist(Stylistwanted);
        ++cur;
    }
}

// Services will be preloaded, and have the option to add additional services
void Holders::CreateVectorOfServices(int thesize, QString *nameofserv, int *servlen, float *servcost)
{
    QVector<service> theservicevector(thesize);

    QVector<service>::Iterator first = theservicevector.begin(), toofar = theservicevector.end(), cur;
    int counter = 0;

    cur = first;
    while(cur != toofar)
      {  cur->SetService(nameofserv[counter]);
        cur->SetServiceCost(servcost[counter]);
        cur->SetServiceLength(servlen[counter]);
        ++cur;
        ++counter;
    }
    servicevector = theservicevector;
}

void Holders::CreateVectorOfStylists(int thesize, QString* firstname, QString* secondname, QString* telephone, int* numberofservicesforstylist)
{
    QVector<stylist> thestylistvector(thesize);
    QVector<stylist>::Iterator first = thestylistvector.begin(), toofar = thestylistvector.end(), cur;
    int count = 0;
    cur = first;
    while(cur != toofar)
       { cur->SetStylistName(firstname[count]);
        cur->SetSurname(secondname[count]);
        cur->SetPhone(telephone[count]);
        cur->SetNumberOfStylistService(numberofservicesforstylist[count]);
       // qDebug() << "works";
      //  cur->CreateArrayOfStylistServices();
        //  THE SERVICES WILL BE READ IN FROM THE FILE THAT WILL BE CREATED,
        // AND AN ARRAY OF THE SERVICES TAKEN IN FROM THE
        // FILE WILL BE CREATED TO BE PUT IN APPENDSTYLISTARRAY
        ++cur;
        ++count;

    }
    stylistvector = thestylistvector;
}

void Holders::AppendToCustomerService(customer addition)
// CHANGE TO TAKE IN STRINGS AND DETAILS ETC SO WE CAN THEN ADD AN OBJECT
{
    customervector.append(addition); //BUT SAYS THAT ARGUMENTS SHOULD BE CONST QVECTOR<CUSTOMER> &l
}

void Holders::AppendToServiceVector(QString servname, int servlength, float servcost)
{
    service temp;
    temp.SetService(servname);
    temp.SetServiceLength(servlength);
    temp.SetServiceCost(servcost);
    servicevector.append(temp);

}

void Holders::AppendToStylistVector(QString name, QString Surname, QString Phone_No, int numofserv)
{
    stylist temp;
    temp.SetStylistName(name);
    temp.SetSurname(Surname);
    temp.SetPhone(Phone_No);
    temp.SetNumberOfStylistService(numofserv);
    stylistvector.append(temp);
}

QVector<customer> Holders::getCustomerVector()
{
    return customervector;
}

QVector<stylist> Holders::getStylistVector()
{
    return stylistvector;
}

QVector<service> Holders::getServiceVector()
{
    return servicevector;
}

