#include <bits/stdc++.h>
#define NMAX 2000

using namespace std;

int n, m, k;
int p[NMAX];
int a[NMAX][NMAX];
int dist[NMAX];
bool sptSet[NMAX];

void read()
{
    ifstream in("text.txt");
    in>>n>>m;
    in>>k;
    int x;
    for(int i = 0; i<k;i++)
    {
        in>>x;
        p[i] = x;
    }
    int y,z;
    for(int i = 0;i<m;i++)
    {
        in>>x>>y>>z;
        a[x][y] = z;
        a[y][x] = z;
    }
}

int minDist()
{
    int Min = INT_MAX, min_index;
    for(int v = 0; v < n;v++)
    {
        if(sptSet[v] = false && dist[v] <= Min)
            Min=dist[v],min_index = v;
    }
    return min_index;
}

void dijkstra(int src)
{
    memset(dist,0,sizeof(dist));
    memset(sptSet,0,sizeof(sptSet));
    
    for(int i = 0;i<n;i++)
    {
        dist[i] = INT_MAX,sptSet[i] = false;
    }
    
    dist[src] = 0;
    
    for(int Count = 0; Count<n-1;Count++)
    {
        int u = minDist();
        sptSet[u] = true;
        
        for(int v = 0; v < n;v++)
        {
            if(!sptSet[v] && a[u][v] && dist[u] != INT_MAX
               && dist[u] + a[u][v] < dist[v])
                dist[v] = dist[u] + a[u][v];
        }
    }

}

void f()
{
    int s = 0;
    dijkstra(1);
    int i;
    s+=dist[p[0]];
    for(i = 1;i<k;i++)
    {
        dijkstra(p[i]);
        s+=dist[p[i]];
    }
    dijkstra(p[i]);
    s+=dist[p[n]];
    cout<<s;
}

int main()
{
    read();
    f();
    return 0;
}
