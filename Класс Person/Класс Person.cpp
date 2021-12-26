#include <iostream>
#include "Person.h"

int main()
{
    try
    {
        Person Adam("Adam", Gender::male);
        Person Eva("Eva", Gender::female);
        Person Vika = *Eva.giveBirth("Vika", Gender::female, &Adam);
        Person Alexey = *Vika.giveBirth("Alexey", Gender::male, &Adam);
        Person Masha = *Eva.giveBirth("Masha", Gender::female, &Alexey);
        Person Oleg = *Masha.giveBirth("Oleg", Gender::male);
        Alexey.Print();
    }
    catch (const char* exception)
    {
        cout << exception;
        return 1;
    }

    return 0;
}