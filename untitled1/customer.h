#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>


class customer{
public:
    void SetCustomerName(QString);
    QString GetCustomerName();
    void SetCustomerService(QString);
    QString GetCustomerService();
   // Took out and put in time slot void Walk_in(Customer,int);
    // THOUGH  MAYBE MOVE TO TIMETABLE??
    void SetCustomerStylist(QString);
    QString GetCustomerStylist();


    //   customer const* CustomerSelf(QString) const;


private:
    QString Name;
    QString ServiceRequired;
    QString StylistRequired;

}; // DO CLASSES NEED ; AFTER CLASSES  IN QT?

#endif // CUSTOMER_H
