#ifndef STYLIST_H
#define STYLIST_H

#include "service.h"
#include <QString>
#include <QVector>

class stylist{ // is this how you declare class is it by header name
public:
    void SetStylistName(QString);
    QString GetStylistName() const;
    void SetNumberOfStylistService(int);
    int GetNumberOfStylistService() const;

    // ORIGINALLY TOOK IN A DOUBLE POINTER TO AN ARRAY FOR THE
    // LIST OF SERVICES, MAY NOT BE NECESSARY TO HAVE
    // A DOUBLE POINTER AS IT WOULD IF IT WAS BEING
    // CALLED IN MAIN, BUT IT IS UNSURE WHERE THIS
    // WILL BE PLACES WHEN THE CODES ARE LINKED
    // TOGETHER
  //  void CreateArrayOfStylistServices(/*Possibly take in  double pointer*/);

    // JUST TO PRINT THE LIST OF ALL THE SERVICES
    // THE STYLIST OFFERS. TO CHOOSE THE SERVICE,
    // WHEN THE CODES ARE LINKED, THE STYLIST SELF
    // FUNCTION COULD BE USED SO WHEN THE BOX OF
    // THE REQUIRED SERVICE IS CLICKED, OR THE NAME
    // IS ENETERED, THE FUNCTION CHOOSES THE THE
    // MATCHING ONE FROM THE ARRAY
    void GetStylistServices(/*Possibly take in  double pointer*/);
    void AppendStylistArray(const service*);
    void SetSurname(QString);
    QString GetSurname() const;


    //  stylist const* Self(QString) const;


    void SetPhone(QString);
    QString GetPhone() const;
    /*
    float PredictedIncome();
    float ActualIncome();*/

    void CreateVectorOfAvailability(QString);
    QVector<QString> GetVectorOfAvailability();
    void CreateVectorOfVectorOfHours(QVector<int>);
    QVector<QVector<int>> GetVectorOfHours();
private:
    QVector<QString> Availability;
    QVector<QVector<int>> hours;
    QString Name;
    QString Surname;
    QString Phone_No;
    int NumberOfStylistServices;
    service* AllServices; // make  pointer to service class;


};

#endif // STYLIST_H
