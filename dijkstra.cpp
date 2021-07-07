#include<bits/stdc++.h>
#define inf 1000000
using namespace std;
int n,a[100][100],truoc[100],d[100],s;
bool chuaxet[100];
void readdata()
{   
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0)
                a[i][j]=inf;
        }
            
}
void init()
{
    for(int v=1;v<=n;v++){
        d[v]=a[s][v];
        truoc[v]=s;
        chuaxet[v]=true;
    }
    d[s]=0;
    chuaxet[s]=false;
}
void dijkstra()
{
    init();
    for(int i=1;i<=n;i++)
    {
        if(chuaxet[i])
        {
            //Kiem tra co duong di ngan hon toi dinh do ko
            int u=0,du=inf;
            for(int z=1;z<=n;z++)
            {
                if(chuaxet[z] && d[z]<du){
                    u=z;
                    du=d[z];
                }
            }
            if(u!=0)    
            {
                chuaxet[u]=false;
                for(int v=1;v<=n;v++)
                {
                    if(chuaxet[v]==true && d[v]>d[u]+a[u][v])
                    {
                        d[v]=d[u]+a[u][v];
                        truoc[v]=u;                        
                    }
                    
                }                
            }
            else{
                chuaxet[i]=false;
            }
            i=0;
        }
    }
    //in ra khoang cach
    for(int t=1;t<=n;t++)
    {
        if(d[t]==inf)
            cout<<"\nK/c "<<s<<" -> "<<t<<" = INF;";
        else 
        {
            cout<<"\nK/c "<<s<<" -> "<<t<<" = "<<d[t]<<";";
            cout<<"\t"<<t<<" <- ";
            int tmp=truoc[t];
            while(tmp!=s)
            {
                cout<<tmp<<" <- ";
                tmp=truoc[tmp];
            }          
            cout<<s;  
        }

    }
}
int main()
{
    readdata();
    init();
    dijkstra();
}