#include "Lista.h"

Lista::Lista()
{
    cabeza = NULL;
}

void Lista::agregar(string t, string *m , int n)
{
    if( cabeza == NULL )
    {
        Nodo *tmp = new Nodo(t, m , n);
        cabeza = tmp;
        return;
    }
    else
    {
        Nodo *p = cabeza;
        while( p->next )
        {
             p = p->next;
        }
        p->next = new Nodo(t, m , n);
    }
}

void Lista::cargar(char *d)
{
    string day;
    string *h;
    int k = 0;
    char buff[100];
    ifstream file;
    file.open(d,ios::app);
    while(!file.eof())
    {
        file >> day;
        file.getline(buff,100);
    }
    file.close();
}


void Lista::buscar(Lista *t)
{
    int k = 0;
    Nodo *tmp = cabeza;
    Nodo *tmp2 = t->cabeza;
    while(tmp->next == NULL || tmp2->next == NULL)
    {
        if(tmp->day != tmp2->day)
        {
            tmp = tmp->next;
        }
        else
        {
            while(k < tmp->total)
            {
                int m = tmp->hours[k][0]*10 + tmp->hours[k][1]*1;
                int n = tmp2->hours[k][0]*10 + tmp2->hours[k][1]*1;
                int o = tmp->hours[k][6]*10 + tmp->hours[k][7]*1;
                if(n >= m && n <= o)
                {
                    cout << tmp->hours[k];
                }
                k++;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
    }
}


Lista::~Lista()
{
    //dtor
}
