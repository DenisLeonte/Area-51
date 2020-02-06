#include <iostream>
#include <fstream>

using namespace std;

struct Nod{
    int nrCrt;
    int nota1;
    int nota2;
    float media;
    Nod *urm;
}*prim,*ultim;

void print()
{
    Nod *p;
    p = prim;
    while(p!= NULL)
    {
        cout<<p->nrCrt<<" "<<p->nota1<<" "<<p->nota2<<" "<<p->media<<endl;
        p = p->urm;
    }
}

int main()
{
    ifstream in("text.txt");
    int x,y,i = 1;
    while(in>>x>>y)
    {
        Nod *nou;
        nou = new Nod;
        nou->nrCrt = i;
        i++;
        nou->nota1 = x;
        nou->nota2 = y;
        nou->media = (x + y) / 2;
        nou->urm = NULL;
        if(prim == NULL)
        {
            prim = ultim = nou;
        }
        else
        {
            ultim->urm = nou;
            ultim = nou;
        }
    }
    print();
    return 0;
}
