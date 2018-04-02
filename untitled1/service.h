#ifndef SERVICE_H
#define SERVICE_H

#include <Qstring>

class service
{
public:
    void SetNumberOfServices(int); // UNNECESSARY??
    int GetNumberOfServices();     // UNNECESSARY??
    void SetService(QString);
    QString GetService() const;

    // TO BE USED WHEN ADDING SERVICES,
    // TAKES IN THE SERVICE NAME, IF IT IS THE SAME
    // AS ONE IN THE ARRAY OF SERVICES THEN IT WILL BE RETURNED,
    // AND DOESN'T NEED TO BE ADDED, OTHERWISE IT WILL BE APPENDED
    // TO THE VECTOR
    // SHOULD BE CALLED AND ITERATE THROUGH THE VECTOR, COMPARING
    // EACH SERVICE NAME IN THE VECTOR WITH THE SERVICE NAME TAKEN
    // IN


    //service const* Serviceself(QString) const; //CHECK


    void SetServiceLength(int);
    int GetServiceLength() const;
    void SetServiceCost(float);
    float GetServiceCost() const;
private:
    QString ServiceName;
    int Servicelength;
    float ServiceCost;
    int NumberOfServices; // change to predefined???
};

#endif // SERVICE_H
