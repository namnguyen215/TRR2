#include<bits/stdc++.h>
#define m 100
using namespace std;

class dt{
    int n;
    int a[m][m];
    public:
        bool chuaxet[m];
        void readdata();
        void reinit();
        void DFS(int u);
        int tplt();
        void cau();
};
void dt::readdata(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
}
void dt::reinit(){
    for(int i=1;i<=n;i++) chuaxet[i]=true;
}
void dt::DFS(int u){
    chuaxet[u]=false;
    for(int k=1;k<=n;k++)
        if(a[u][k]==1&& chuaxet[k]==true)
            DFS(k);
}
int dt::tplt(){
    for(int i=1;i<=n;i++)
        if(chuaxet[i]==true) return 0;
    return 1;
}
void dt::cau(){
    readdata();
    reinit();
    for(int u=1;u<n;u++)
        for(int v=u+1;v<=n;v++)
            if(a[u][v]==1){
                a[u][v]=0;
                a[v][u]=0;
                DFS(1);
                if(tplt()==0) cout<<u<<" "<<v<<endl;
                a[u][v]=1;
                a[v][u]=1;
                reinit();
            }
}
int main(){
    dt g;
    g.cau();
}

