#include<bits/stdc++.h>
using namespace std;
ifstream f("lista.in");

struct nod
{
    string nume;
    string autor;
    float nota;
    int pret;
    nod *urm;
}*prim,*ultim;

int N = 0;
void citire()
{
    int n;
    string nume;
    string autor;
    float nota;
    int pret;
    while(f>>nume>>nota>>pret>>autor)
    {
        N++;
        nod *n;
        n = new nod;
        n->nume = nume;
        n->nota = nota;
        n->pret = pret;
        n->autor = autor;
        n->urm = NULL;
        if(prim==NULL)
        {
            prim = ultim = n;
        }
        else
        {
            ultim->urm = n;
            ultim = n;
        }
    }
}
void afis()
{
    nod *p=prim;
    while(p != NULL)
    {
        cout<<p->nume<<" "<<p->nota<<" "<<p->pret<<" "<p->autor<<endl;
        p=p->urm;
    }
}

void sortare()
{
    vector <string> x;
    nod *p = prim;
    while(p != NULL)
    {
        x.push_back(p->nume);
        p = p->urm;
    }
    sort(x.begin(),x.end());
    for(auto it:x)
    {
        cout<<it<<endl;
    }
}

float suma()
{
    int s=0;
    nod*p=prim;
    while(p!=NULL)
    {
        s+=p->nota;
        p=p->urm;
    }
    return s;
}

int pretMax()
{
    int Max = 0;
    vector <int> x;
    nod *p = prim;
    while(p != NULL)
    {
        x.push_back(p->pret);
        p = p->urm;
    }
    for(auto it:x)
    {
        if(it>=Max)
            Max = it;
    }
    return Max;
}

int pretMin()
{
    int Min = INT_MAX;
    vector <int> x;
    nod *p = prim;
    while(p != NULL)
    {
        x.push_back(p->pret);
        p = p->urm;
    }
    for(auto it:x)
    {
        if(it<=Min)
            Min = it;
    }
    return Min;
}

void check(vector <string> x,int &f)
{
    for(auto it:x)
    {
        if(it == name)
            f++;
    }
}

void autor()
{
    nod *p = prim;
    int k[500];
    memset(k,0,sizeof(k));
    vector <string> names;
    while(p!=NULL)
    {
        names.push_back(p->autor);
        p = p->urm;
    }
    p = prim;
    while(p!=NULL)
    {
        check()
        p = p->urm;
    }
}

int main()
{
    citire();
    afis();
    cout<<endl;
    sortare();
    cout<<endl;
    cout<<"Media Rating-urilor"<<suma()/N;
    cout<<endl;
    cout<<"Cartea ce-a mai scumpa este: "<<pretMax();
    cout<<endl;
    cout<<"Cartea ce-a mai ieftina este: "<<pretMin();
    return 0;
}
