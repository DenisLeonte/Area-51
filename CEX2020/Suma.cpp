#include <iostream>
#include <bits/stdc++.h>
#define NMAX 20
#define MMAX 4000

using namespace std;

vector<int> a[MMAX][NMAX];
int n,k;

void read()
{
    k = 1;
    int l = 1;
    int i = 0;
    ifstream in("text.txt");
    int x;
    in>>n;
    in>>x;
    a[1][k].push_back(x);
    k++;
    while(in>>x)
    {
        if(i == pow(k,2))
        {
            i = 0;
            k++;
            l = 1;
        }
        if(l == k)
        {
            l++;
        }
        a[l][k].push_back(x);
        i++;
    }
    cout<<k;
}

int main()
{
    read();
    return 0;
}
