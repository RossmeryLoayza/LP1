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
    int t = 0;
    char buff[100];
    for (int i = 0 ; i < 100 ; i++)
        buff[i] = 'a';
    ifstream file;
    file.open(d,ios::app);
    while(!file.eof())
    {
        int n = 5;
        file >> day;
        file.getline(buff,100);
        while (buff[t] != '/n')
        {
            if(buff[t] == ' ')
            {
                k++;
            }
            t++;
        }
        for (int i = 0 ; i < 100 ; i++)
            buff[i] = 'a';
        cout << k << endl;
        h = new string [k];
        for(int i = 0 ; i < k ; i++)
        {
            h[i].copy(buff,11,n);
            n = n + 11;
        }
        this->agregar(day,h,k);
        k = t = 0;
    }
    file.close();
}


void Lista::buscar(Lista *t)
{
    int tiempo;
    cin >> tiempo;
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
                    cout << tmp-> day << "  " << tmp->hours[k];
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
