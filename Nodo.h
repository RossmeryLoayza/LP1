#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

class Nodo
{
    public:
        string day;
        string *hours;
        int total;
        Nodo *next;
        Nodo();
        Nodo(string t, string *m , int n);
        virtual ~Nodo();
};

#endif // NODO_H
