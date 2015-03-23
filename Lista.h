#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista
{
    public:
        Lista();
        void agregar(string t, string *m , int n);
        void buscar(Lista *t);
        void cargar(char *d);
        virtual ~Lista();
    protected:
        Nodo *cabeza;
};

#endif // LISTA_H
