//Chu trình đi qua tất cả các cạnh của đồ thị là chu trình euler


#include<bits/stdc++.h>
using namespace std;
int n,u,a[100][100];
void readdata()
{
    cin>>n>>u;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
}
void Euler_Circuit()
{
    stack<int> st;
    vector<int> CE;
    st.push(u);                                 //Xet tu dinh u
    while(!st.empty())
    {
        int s=st.top();
        bool ok=false;
        for(int j=1;j<=n;j++)
        {
            if(a[s][j]==1)                      //Co duong di tu s den j
            {
                ok=true;
                st.push(j);                     //Dua j vao stack
                a[s][j]=0;a[j][s]=0;            //Danh dau canh [s][j] la da xet
                break;
            }
        }
        if(ok==false)
        {
            int s=st.top();st.pop();
            CE.push_back(s);
        }
    }
    for(int i=CE.size()-1;i>=0;i--)
        cout<<CE[i]<<" ";
}
int main()
{
    readdata();
    Euler_Circuit();
}