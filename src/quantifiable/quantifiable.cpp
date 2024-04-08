// Include header file
#include <tubesoop1/quantifiable/quantifiable.h>
// #include "../../include/tubesoop1/quantifiable/quantifiable.h"

// Constructor implementation with validation
template <class T>
inline Quantifiable<T>::Quantifiable(T& val, int qty) : value(val) {
    if (qty >= 0) {
        value = val;
        quantity = qty;
    } else {
        throw invalid_argument("Quantity cannot be negative.");
    }
}

// Set quantity implementation with validation
template <class T>
inline void Quantifiable<T>::setQuantity(int qty) {
    // if (qty >= 0) {
    //     quantity = qty;
    // } else {
    //     throw invalid_argument("Quantity cannot be negative.");
    // }
}

// Operator += implementation
template <class T>
inline void Quantifiable<T>::operator+=(int qty) {
    if(quantity != -1){
        quantity += qty;
    }
}

/**
     * @brief Operator += to increment the quantity by a given value
     * 
     * @param qty Value to add to the quantity
     */
template <class T>
inline void Quantifiable<T>::operator+=(Quantifiable<T> other){
    quantity += other.quantity;
}

// Operator -= implementation with validation
template <class T>
inline void Quantifiable<T>::operator-=(int qty) {
    if(quantity != -1){
        if (quantity - qty >= 0) {
            quantity -= qty;
        } else {
            throw invalid_argument("Quantity cannot be negative.");
        }
    }
}

// Operator ++ (postfix) implementation
template <class T>
inline Quantifiable<T> Quantifiable<T>::operator++(int) {
    Quantifiable<T> temp = *this;
    ++quantity;
    return temp;
}

// Operator -- (postfix) implementation with validation
template <class T>
inline Quantifiable<T> Quantifiable<T>::operator--(int) {
    if(quantity != -1){
        if (quantity - 1 >= 0) {
            Quantifiable<T> temp = *this;
            --quantity;
            return temp;
        } else {
            throw invalid_argument("Quantity cannot be negative.");
        }
    }
}

/**
 * @brief Check if both Quantifiable has the same value
 * 
 * @param other 
 * @return true if same
 */
template <class T>
inline bool Quantifiable<T>::operator==(Quantifiable<T> other){
    return value == other.value && quantity == other.quantity;
}

// Todo: Delete this main function if not needed (only for testing purpose)
// int main() {
//     int value = 10;
//     Quantifiable<int> q(value, 5);

//     cout << "Initial Value: " << q.getValue() << endl;
//     cout << "Initial Quantity: " << q.getQuantity() << endl;

//     q += 3; // quantity = 8
//     cout << "Quantity after += 3: " << q.getQuantity() << endl;
//     try {
//         q -= 10; // quantity menjadi negatif, akan melemparkan pengecualian
//     } catch (invalid_argument& e) {
//         cerr << "Error: " << e.what() << endl;
//     }

//     q++; 
//     cout << "Quantity after ++: " << q.getQuantity() << endl;

//     q--; // prefix decrement, quantity = 8
//     cout << "Quantity after --: " << q.getQuantity() << endl;

//     return 0;
// }