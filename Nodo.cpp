#include "Nodo.h"

Nodo::Nodo()
{
    day = "";
    total = 0;
    next = NULL;
}

Nodo::Nodo(string t , string *m , int n)
{
    day = t;
    total = n;
    hours = new string[n];
    for (int i = 0 ; i < n ; i++)
    {
        hours[i] = m[i];
    }
    next = NULL;
}

Nodo::~Nodo()
{
    //dtor
}
