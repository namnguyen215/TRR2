#include<bits/stdc++.h>
using namespace std;
class Dothi{
    int n;
    int a[100][100];
    public:
    bool chuaxet[100];
    void readdata();
    void init();
    // void dequydfs(int u);
    void queuedfs(int u);
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

void Dothi::queuedfs(int u)
{
    queue<int> q;
    cout<<" "<<u;
    q.push(u);
    chuaxet[u]=false;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(int v=1;v<=n;v++)
        {
            if(chuaxet[v] && a[s][v]==1)
            {
                cout<<" "<<v;
                chuaxet[v]=false;
                q.push(v);
            }
        }
    }
}
int main()
{
    Dothi G;
    G.readdata();
    G.init();
    // G.dequydfs(1);
    // G.init();
    G.queuedfs(1);
}