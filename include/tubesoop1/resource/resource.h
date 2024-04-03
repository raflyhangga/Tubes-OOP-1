#ifndef RESOURCE_H
#define RESOURCE_H

/**
 * Suatu abstract class untuk semua item yang bisa disimpan dalam
 * suatu inventory
*/
class Resource{
    private:
        int anAttribute;
    public:
        void anMethod();
        Resource();
        virtual friend bool operator==(Resource&,Resource&);
};

#endif