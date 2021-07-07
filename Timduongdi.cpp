#include<bits/stdc++.h>
using namespace std;
int n,a[100][100],truoc[100],s,t;
bool chuaxet[100];
void readdata()
{
    cin>>n;
    cin>>s>>t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
}
void init()
{
    for(int i=1;i<=n;i++){
        chuaxet[i]=true;
        truoc[i]=0;
    }
        
}
void dequydfs(int u)
{   //Xet dinh u
    chuaxet[u]=false;       //Danh dau da xet dinh u
    for(int v=1;v<=n;v++)   //Duyet cac dinh ke voi dinh u
    {
        if(a[u][v]==1 && chuaxet[v]==true){
            dequydfs(v);
            truoc[v]=u;
        }
    }
}
void queuebfs(int u)
{
    queue<int> q;
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
                chuaxet[v]=false;
                q.push(v);
                truoc[v]=s;
            }
        }
    }
}
void duongdi(string x)
{
    if(truoc[t]==0){
        cout<<"no path";
        return;
    }
    else
    {
        int u=truoc[t];
        cout<<x<<t<<" ";
        while(u!=s){
            cout<<u<<" ";
            u=truoc[u];
        }
        cout<<s<<endl;
    }
}
int main()
{
    readdata();
    init();
    dequydfs(1);
    duongdi("DFS path: ");
    init();
    queuebfs(1);
    duongdi("BFS path: ");
}