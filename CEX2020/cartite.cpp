#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

ifstream in("cartite.in");
ofstream out("cartite.out");

int N,M,XC,YC,k;
int a[205][205];

    int di[8] = {-1,0,0,1,1,-1,1,-1};
    int dj[8] = {0,-1,1,0,1,1,-1,-1};

struct point
{
    int x;
    int y;
};

struct queue_node
{
    point pt;
    int dist;
};

struct galerie
{
    int x1,y1;
    int x2,y2;
};

bool check(int x,int y)
{
    if(a[x][y] == 0)
        return false;
    return true;
}

bool ok(int i,int j)
{
    if(i<1||j<1||i>N||j>M)
        return false;
    if(a[i][j] == -1)
        return false;
    return true;
}

int lee(point src,point dest)
{
    if(!a[src.x][src.y] || !a[dest.x][dest.y])
        return -1;
    bool viz[N][M];
    memset(viz,false,sizeof(viz));
    viz[src.x][src.y] = true;
    queue <queue_node> q;

    queue_node s = {src,0};
    q.push(s);
    while(!q.empty())
    {
        queue_node curr = q.front();
        point pt = curr.pt;
        if(pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        q.pop();
        for(int i = 0;i<4;i++)
        {
            int row = pt.x+di[i];
            int col = pt.y+dj[i];

            if(ok(row,col) && a[row][col] &&!viz[row][col])
            {
                viz[row][col] = true;
                queue_node adjcell = { {row,col},
                                        curr.dist+1};
                q.push(adjcell);
            }
        }
    }

}

void marcare(int x, int y, int p)
{
    if(check(x,y))
    {
    if(p == 0)
        a[x][y] = -1;
    else if(p == 1)
    {
        a[x][y] = -1;
        for(int i = 0;i<4;i++)
        {
            a[x+di[i]][y+dj[i]] = -1;
        }
    }
    else
    {
        a[x][y] = -1;
        for(int i = 0;i<8;i++)
        {
            a[x+di[i]][y+dj[i]] = -1;
        }
        a[x+2][y] = a[x][y+2] = a[x-2][y] = a[x][y-2] = -1;
    }
    }
}


    vector <galerie> g;

void citire()
{
    int p;
    in>>p;
    in>>N>>M;
    for(int i = 1; i<= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            a[i][j] = 1;
        }
    }
    in>>XC>>YC;
    in>>k;
    int x,y;
    for(int i = 0; i<k;i++)
    {
        in>>x>>y>>p;
        marcare(x,y,p);
    }
    in>>k;
    for(int i = 0; i<k ;i++)
    {
        galerie ex;
        in>>ex.x1>>ex.y1>>ex.x2>>ex.y2;
        g.push_back(ex);
    }

}

void distMin()
{
    int Min = INT_MAX;
    point src = {XC,YC};
    point MMin;
    for(auto it:g)
    {
        int aux;
        point dest1 = {it.x1,it.y1};
        aux = lee(src,dest1);
        if(aux<Min)
        {
            Min = aux;
            MMin = dest1;
        }
    }
    out<<MMin.x<< " " <<MMin.y<< " " <<Min<<endl;
}

int main()
{
    citire();
    //cout<<lee(a,b);
    distMin();
    return 0;
}
