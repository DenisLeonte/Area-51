#include<bits/stdc++.h>
using namespace std;
ifstream f("lista.in");

struct nod
{
    string nume;
    float nota;
    nod *urm;
};
nod *prim,*ultim;

void citire()
{
    int n;
    string nume;
    float nota;
    while(f>>nume>>nota)
    {
        nod *n;
        n = new nod;
        n->nume = nume;
        n->nota = nota;
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
    for(auto it:x)
    {
        cout<<it<<endl;
    }
}

int main()
{
    citire();
    afis();
    cout<<endl;
    sortare();
    return 0;
}
