#include <bits/stdc++.h>
using namespace std;

ifstream f("date.in");
struct medicament
{
    //Modificat char in string for better performance and memory management
    string denumire;
    float pret;
    float cantitate;
    float pretcumparare;
};

struct nod
{
    medicament inf;
    nod *urm;
};
nod*prim, *ultim;

void adaugare(nod*&prim,medicament x)
{
    nod*nou=new nod;
    nou->inf=x;
    nou->urm=prim;
    prim=nou;
}

//Aici am modificat citirea din cauza ca ma enerva cum era mai devreme
void citire()
{
    medicament x;
    while(f>>x.denumire>>x.pret>>x.cantitate>>x.pretcumparare)
    {
        nod *nou = new nod;
        nou->inf = x;
        nou->urm = NULL;
        if(prim==NULL)
        {
            prim = ultim = nou;
        }
        else
        {
            ultim->urm = nou;
            ultim = nou;
        }
    }
}

void afisare(nod*prim)
{
    nod*p=prim;
    cout<<"Medicamente ce sunt pe stoc:"<<endl;
    while(p!=NULL)
    {
        cout<<p->inf.denumire<<endl;
        p=p->urm;
    }
    cout<<endl;
}

float pretMinim()
{
    nod*p=prim;
    float Min=p->inf.pret;
    while(p!=NULL)
    {
        if(p->inf.pret<Min){
            Min=p->inf.pret;
        }
        p=p->urm;
    }
    return Min;
}

float cantMax()
{
    nod*p=prim;
    float Max=p->inf.cantitate;
    while(p!=NULL)
    {
        if(p->inf.cantitate>Max){
            Max=p->inf.cantitate;
        }
        p=p->urm;
    }
    return Max;
}

float costulstocului()
{   nod*p=prim;
    float pret=0,c,v;

    while(p!=NULL)
    {   c=p->inf.cantitate;
        v=p->inf.pretcumparare;
        pret=pret+c*v;
        p = p->urm;
    }
    return pret;
}

string nameMatch(float x)
{
    nod *p = prim;
    while(p!=NULL)
    {
        if(p->inf.pret == x)
            return p->inf.denumire;
        p = p->urm;
    }
    return "N/A";
}

void sortare()
{
    //Aici am creeat un vector de preturi
    vector <float> p;
    nod *a = prim;
    while(a!=NULL)
    {
        //Aici am adaugat preturile la vector unu cate unu
        p.push_back(a->inf.pret);
        a = a->urm;
    }
    cout<<endl<<"Medicamentele sortate dupa pret :\n";
    sort(p.begin(),p.end());
    //For this for to work just go to Settings>Compiler>Have g++ follow the C++11 ISO C++ language standard
    for(auto it:p)
    {
        cout<<nameMatch(it)<<" "<<it<<endl;
    }
}

int main()
{
    citire();
    afisare(prim);
    cout<<"Cel mai mic pret pentru un medicament este de "<<pretMinim()<<" lei."<<endl;
    cout<<"Cele mai multe medicamente in stoc sunt in numar de "<<cantMax()<<" de cutii."<<endl;
    cout<<"Suma data pe medicamentele din stoc este de "<<costulstocului()<<" de lei."<<endl;
    sortare();
    return 0;
}
