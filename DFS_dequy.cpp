#include<bits/stdc++.h>
using namespace std;
class Dothi{
    int n;
    int a[100][100];
    public:
    bool chuaxet[100];
    void readdata();
    void init();
    void dequydfs(int u);
};
void Dothi::readdata()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
}
void Dothi::init()
{
    for(int i=1;i<=n;i++)
        chuaxet[i]=true;
}
void Dothi::dequydfs(int u)
{
    cout<<" "<<u;   //Xet dinh u
    chuaxet[u]=false;       //Danh dau da xet dinh u
    for(int v=1;v<=n;v++)   //Duyet cac dinh ke voi dinh u
    {
        if(a[u][v]==1 && chuaxet[v]==true)
            dequydfs(v);
    }
}
int main()
{
    Dothi G;
    G.readdata();
    G.init();
    G.dequydfs(1);
}