#include <iostream>
#include <vector>
#include <fstream>
#define N_MAX 666013

using namespace std;

vector <int> T[N_MAX];
int M = N_MAX;

int f(int x)
{
    return x%M;
}

bool cautare(int x)
{
    int p = f(x);
    for(auto it:T[p])
    {
        if(it == x)
            return true;
    }
    return false;
}

void stergere(int x)
{
    int p = f(x);
    int n =sizeof(T[p]);
    if(cautare(x))
    {
        for(int it = 0; it!= n;it++)
        {
            if(x == T[p][it])
            {
                for(int j = it; j != n; j++)
                {
                    T[p][j] = T[p][j+1];
                }
                break;
            }
        }
    }
}

void inserare(int x)
{
    int p = f(x);
    if(!cautare(x))
    {
        T[p].push_back(x);
    }
}

int main()
{
    ifstream in("text.txt");
    int a;
    while(in>>a)
    {
        inserare(a);
    }
    cout<<cautare(27627)<<endl;
    stergere(27626);
    cout<<cautare(27626)<<endl;
    inserare(5698527);
    cout<<cautare(5698527)<<endl;
    stergere(5698527);
    cout<<cautare(5698527)<<endl;

    return 0;
}
