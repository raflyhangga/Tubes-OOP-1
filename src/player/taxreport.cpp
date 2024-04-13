#include "tubesoop1/player/taxreport.h"

TaxReport::TaxReport(string name, string type, int tax){
    this->name = name;
    this->type = type;
    this->tax = tax;
}
string TaxReport::getName() const {
    return name;
}
string TaxReport::getRole()const {
    return type;
}
int TaxReport::getTax() const {
    return tax;
}
ostream &operator<<(ostream &os, const TaxReport &t){
    os << t.name << " - " << t.type << ": " << t.tax << " gulden" << endl;
    return os;
}
