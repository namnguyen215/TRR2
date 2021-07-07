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
        int tplt();
        void tru();
        void BFS(int u);
};

void dt::readdata(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
}
void dt::reinit(){
    for(int i=1;i<=n;i++) chuaxet[i]=true;
}
void dt::BFS(int u){
    chuaxet[u]=false;
    queue<int> hd;
    hd.push(u);
    while(!hd.empty()){
        int s=hd.front();
        hd.pop();
        for(int v=1;v<=n;v++){
            if(a[s][v]==1&&chuaxet[v]==true){
                hd.push(v);
                chuaxet[v]=false;
            }
        }
    }
}
int dt::tplt(){
    for(int i=1;i<=n;i++)
        if(chuaxet[i]==true) return 0;
    
    return 1;
}
void dt::tru(){
    readdata();
    reinit();
    for(int i=1;i<=n;i++){
    	chuaxet[i]=false;
    	if(i==1) BFS(2);
        else BFS(1);
        if(tplt()==0) cout<<i<<" ";
        reinit();
    }
}
int main(){
    dt g;
    g.tru();
}

  
