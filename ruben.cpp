#include<bits/stdc++.h>
using namespace std;
ifstream f("lista.in");

struct nod
{
    string nume;
    float nota;
    nod *urm;
};
nod *prim;
void adaugf(string nume1,float n1)
{
    nod *nou= new nod;
    nou->nume = nume1;
    nou->nota = n1;
    nou->urm=prim;
    prim=nou;
}
void citire()
{
    int n;
    string nume;
    float nota;
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>nume>>nota;
        adaugf(nume,nota);
    }
}
void afis()
{
    nod *p=prim;
    while(p != NULL)
    {
        cout<<p->nume<<" "<<p->nota<<endl;
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
    for(auto &it:x)
    {
        cout<<it<<endl;
    }
}

int main()
{
    citire();
    afis();
    sortare();
    return 0;
}
