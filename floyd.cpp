#include<bits/stdc++.h>
using namespace std;
int n,a[100][100],d[100][100],next[100][100];
bool chuaxet[100];
void readdata()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
}
void init()
{
    for(int i=1;i<=n;i++){
        chuaxet[i]=true;
    }
}
int main()
{
    readdata();
    init();
    floyd();
}