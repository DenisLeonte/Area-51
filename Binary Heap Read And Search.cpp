#include <iostream>
#include <fstream>
#include <vector>
#define N_MAX 8000

using namespace std;

int t[N_MAX], val[N_MAX], st[N_MAX], dr[N_MAX];
int rad;

void sdr(int x)
{
    if(x)
    {
        sdr(st[x]);
        sdr(dr[x]);
        cout<<x<<" ";
    }
}

void srd(int x)
{
    if(x)
    {
        srd(st[x]);
        cout<<x<<" ";
        srd(dr[x]);
    }
}

void rsd(int x)
{
    if(x)
    {
        cout<<x<<" ";
        rsd(st[x]);
        rsd(dr[x]);
    }
}

int main()
{
    ifstream in("text.in");
    int n;
    in>>n;
    for(int i = 1; i<=n;i++)
    {
        in>>val[i]>>st[i]>>dr[i];
        t[st[i]] = i;
        t[dr[i]] = i;
        if(!t[i])
        {
            rad = i;
        }
    }
    rsd(rad);
    cout<<endl;
    srd(rad);
    cout<<endl;
    sdr(rad);
    return 0;
}
