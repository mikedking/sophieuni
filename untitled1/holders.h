#ifndef HOLDERS_H
#define HOLDERS_H

#include <Qstring>
#include "stylist.h"
#include "service.h"
#include "customer.h"
#include <QVector>

class Holders
{
  public:
    void CreateVectorOfServices(int,QString*, int*, float*);
    void CreateVectorOfStylists(int,QString*,QString*,QString*,int*);
    void CreateVectorOfCustomers(int);

    void AppendToServiceVector(QString, int, float);
    void AppendToCustomerService(customer);
    void AppendToStylistVector(QString, QString, QString,int);
    QVector<customer> getCustomerVector();
    QVector<stylist> getStylistVector();
    QVector<service> getServiceVector();
private:
    QVector<service> servicevector;
    QVector<stylist> stylistvector;
    QVector<customer> customervector;


};


#endif // HOLDERS_H

