#ifndef QUANTIFIABLE_H
#define QUANTIFIABLE_H
#include <iostream>
using namespace std;

/**
 * @brief Header guard for Quantifiable class template
 */
template <class T>
class Quantifiable
{
private:
    T value;
    int quantity;

public:
    /**
     * @brief Constructor to initialize Quantifiable object
     * 
     * @param val Initial value
     * @param qty Initial quantity
     */
    Quantifiable(T& val, int qty);

    /**
     * @brief Get the value of the Quantifiable object
     * 
     * @return T Value of the object
     */
    T getValue() const
    {
        return value;
    }

    /**
     * @brief Get the quantity of the Quantifiable object
     * 
     * @return int Quantity of the object
     */
    int getQuantity() const
    {
        return quantity;
    }

    /**
     * @brief Set the value of the Quantifiable object
     * 
     * @param val New value to set
     */
    void setValue(T val)
    {
        value = val;
    }

    /**
     * @brief Set the quantity of the Quantifiable object
     * 
     * @param qty New quantity to set
     */
    void setQuantity(int qty);

    /**
     * @brief Operator += to increment the quantity by a given value
     * 
     * @param qty Value to add to the quantity
     */
    void operator+=(int qty);

    /**
     * @brief Operator += to increment the quantity by a given value
     * 
     * @param qty Value to add to the quantity
     */
    void operator+=(Quantifiable<T> other);

    /**
     * @brief Operator -= to decrement the quantity by a given value
     * 
     * @param qty Value to subtract from the quantity
     */
    void operator-=(int qty);

    /**
     * @brief Postfix increment operator ++ to increment the quantity by 1
     * 
     * @param Unused parameter (int)
     * @return Quantifiable<T> Object before incrementing
     */
    Quantifiable<T> operator++(int);

    /**
     * @brief Postfix decrement operator -- to decrement the quantity by 1
     * 
     * @param Unused parameter (int)
     * @return Quantifiable<T> Object before decrementing
     */
    Quantifiable<T> operator--(int);

    /**
     * @brief Check if both Quantifiable has the same value
     * 
     * @param other 
     * @return true if same
     */
    bool operator==(Quantifiable<T> other);
};

#endif
