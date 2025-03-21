// ============================================================================
// file: cashRegister.cpp
// ============================================================================
// Programmer: Isaias Soria
// Date: 02/08/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Instructor: Dr. Rodriguez
//
// Description: This program is a cash register. It takes in input from the customer on the amount of items then asks for the price of each item.
// Then it calculates subtotal and adds tax for the total and asks for cash or credit. Then it outputs change for cash or charges the credit card.
//
// ============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void)
{
    double tax = .0775;
    double subtotal = 0;
    double total = 0;
    double price = 0;
    double cashPayment = 0;
    int items = 0;
    int counter = 1;
    char payment;

    cout << "How many items?: ";
    cin >> items;

    while(items > 0)
    {
        cout << "Please enter the cost of item #" << counter << ": $";
        cin >> price;
        subtotal += price;
        counter++;
        items--;

    }

    cout << "\nSubtotal: $" << subtotal << endl;
    tax *= subtotal;
    tax = round(tax * 100.0) / 100.0;
    cout << "Tax(7.75%): $" << tax << endl; 
    total = subtotal + tax;
    cout << "Total: $" << fixed << setprecision(2) << total << endl; 

    cout << "Cash or credit? Enter 'C' for Cash or 'T' for Credit: ";
    cin >> payment;

    if (payment == 'c' || payment == 'C')
    {
        cout << "Cash: $";
        cin >> cashPayment;

        while(cashPayment < total)
        {
            cout << "Please enter the correct amount of cash: $";
            cin >> cashPayment;
        }

        cout << "Change: $" << fixed << setprecision(2) << cashPayment - total << endl;
    }

    else if (payment == 't' || payment == 'T')
    {
        cout << "Card Payment: $" << total << endl;
    }

    else
    {
        cout << "Incorrect selection..." << endl;
    }

    return 0;
 
}
