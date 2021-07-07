#include<bits/stdc++.h>
#define inf 1000000
using namespace std;
int v,e,n,s;
int d[100],a[100][100],truoc[100];
void init()
{
    for(int i=1;i<=n;i++)
    {
        d[i]=a[s][i];
        truoc[i]=s;
    }
    d[s]=0;
}

void loop()
{
    for(int k=1;k<=n-2;k++)  //Chi can n-2 buoc la oke
    {
        for(int v=1;v<=n;v++)
        {
            if(v!=s)
            {
                for(int u=1;u<=n;u++)
                {
                    if(d[v]>d[u]+a[u][v] && a[u][v]!=inf && d[u]!=inf)
                    {
                        d[v]=d[u]+a[u][v];
                        truoc[v]=u;
                    }
                }
            }
        }
    }
}
void in()
{
    for(int i=1;i<=n;i++)
    {
        if(d[i]==inf)
            cout<<"K/c "<<s<<" -> "<<i<<" = "<<"INF;";
        else
        {
            cout<<"K/c "<<s<<" -> "<<i<<" = "<<d[i]<<";\t";
            cout<<i<<" <- ";
            int tmp=truoc[i];
            while(tmp!=s)
            {
                cout<<tmp<<" <- ";
                tmp=truoc[tmp];
            }          
            cout<<s;                     

        }
        cout<<endl;
    }
}
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0)
                a[i][j]=inf;
        }
            
    init();
    loop();
    in();
}