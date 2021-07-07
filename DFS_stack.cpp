#include<bits/stdc++.h>
using namespace std;
class Dothi{
    int n;
    int a[100][100];
    public:
    bool chuaxet[100];
    void readdata();
    void init();
    void dequy(int u);
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
void Dothi::dequy(int u)
{
    stack<int> st;
    cout<<" "<<u;
    chuaxet[u]=false;
    st.push(u);
    while(!st.empty())
    {
        int s=st.top();
        st.pop();
        for(int v=1;v<=n;v++)
        {
            if(a[s][v]==1 && chuaxet[v])
            {
                cout<<" "<<v;
                chuaxet[v]=false;
                st.push(s);
                st.push(v);
                break;
            }
        }
    }
}
int main()
{
    Dothi G;
    G.readdata();
    G.init();
    G.dequy(1);
}