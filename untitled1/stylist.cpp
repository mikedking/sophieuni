#include "stylist.h"
#include "service.h"
#include <Qstring>
#include <QVector>
#include <QDebug>

void stylist::SetStylistName(QString Namer)
{
    Name = Namer;
}

QString stylist::GetStylistName() const
{
    return Name;
}

// SET THE NUMBER OF SERVICES THAT THE STYLIST PROVIDES, IN HOLDER
// CLASS WHEN THE STYLIST VECTOR IS CREATED, IT ASKS FOR THE NUMBER OF
// SERVICES EACH STYLIST CAN PERFORM, AND THIS FUNCTION IN CALLED THERE
void stylist::SetNumberOfStylistService(int num)
{
    NumberOfStylistServices = num;
}

int stylist::GetNumberOfStylistService() const
{
    return NumberOfStylistServices;
}


void stylist::AppendStylistArray(const service *serviceobject)
{
    for(int i = 0; i < NumberOfStylistServices; i++)
    {
        if(AllServices[i].GetService() != " ")
            continue;
        else{
            AllServices[i] = *serviceobject;
            break;
        }
    }
}
void stylist::GetStylistServices()
{

    // AGAIN, UNSURE OF SYNTAX CURRENTLY, AND
    // HOW THE ARRAY WILL BE OUTPUT TO THE SCRREN
    qDebug() << "Array is: \n";
    for(int p = 0; p < NumberOfStylistServices; p++)
    {
        qDebug() << AllServices[p].GetNumberOfServices() << " " << endl;
    }

}



/*stylist const* stylist::Self(QString current) const
{
    if(strcmp(this->GetStylistName().c_str(), current.c_str()) == 0)
    {
        return this;
    }
    else
    {
        // OR APPEND TO THE VECTOR WHICH IS IN THE HOLDER CLASS
        // AND SO THE HOLDER OBJECT WILL BE GENERATED WHEN THE DAY IS
        // CREATED, SO THE OBJECT WILL BE CREATED, THEN
        //SYLISTVECTOR.APPEND(THIS);
        return NULL;
    }

} */

// !!!!!!!!!!!!
// !!!!!!!!!!!!
/*float stylist::PredictedIncome()
{

}*/
// !!!!!!!!!!!
// !!!!!!!!!!!

// !!!!!!!!!!!
// !!!!!!!!!!!
/*
float stylist::ActualIncome()
{

}*/
// !!!!!!!!!!
// !!!!!!!!!!

void stylist::SetSurname(QString Sur)
{
    Surname = Sur;
}

QString stylist::GetSurname() const
{
    return Surname;
}

void stylist::SetPhone(QString phone)
{
    Phone_No = phone;
}

QString stylist::GetPhone() const
{
    return Phone_No;
}

void stylist::CreateVectorOfAvailability(QString day)
{
    {
       Availability.append(day);
    }
}

void stylist::CreateVectorOfVectorOfHours(QVector<int> thehours)
{
    hours.append(thehours);
}

QVector<QString> stylist::GetVectorOfAvailability()
{
    return Availability;
}

QVector<QVector<int>> stylist::GetVectorOfHours()
{
    return hours;
}
