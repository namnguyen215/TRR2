#include<bits/stdc++.h>
using namespace std;
int a[100][100],v,u;
bool chuaxet[100];
void Tree_DFS(int u)
{
    chuaxet[u]=false;
    for(int i=1;i<=v;i++)
    {
        if(chuaxet[i] && a[u][i]==1)
        {
            cout<<u<<" "<<i<<endl;
            Tree_DFS(i);
        }
    }
}
void Tree_BFS(int u)
{
    queue<int> q;
    q.push(u);
    chuaxet[u]=false;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(int i=1;i<=v;i++)
        {
            if(chuaxet[i] && a[s][i]==1)
            {
                q.push(i);
                chuaxet[i]=false;
                cout<<u<<" "<<i<<endl;
            }
        }
    }
}
void checkDFS()
{
    memset(chuaxet,true,sizeof(chuaxet));
    cout<<"DFS tree"<<endl;
    Tree_DFS(u);
}
void checkBFS()
{
    memset(chuaxet,true,sizeof(chuaxet));
    cout<<"BFS tree"<<endl;
    Tree_BFS(u);    
}
int main()
{
    cin>>v>>u;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
            cin>>a[i][j];
    checkDFS();
    checkBFS();
}