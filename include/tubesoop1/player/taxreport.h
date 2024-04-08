#ifndef TAX_REPORT_H
#define TAX_REPORT_H

#include <string>
#include <iostream>

using namespace std;

class TaxReport
{
    private:
        string name;
        string type;
        int tax;
    public:
        TaxReport(string _name, string _type, int _tax);
        string getName() const;
        string getType() const;
        int getTax()  const;
        friend ostream &operator<<(ostream &os, const TaxReport &t);
};

#endif