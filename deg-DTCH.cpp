#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v=11;
    int ra[100]={0},vao[100]={0};
    for(int i=1;i<=11;i++)
    {
        int num,v1,v2;
        cin>>num;
        cin>>v1;
        for(int i=1;i<=num;i++)
        {
            cin>>v2;
            ra[v1]++;
            vao[v2]++;
        }
    }
    for(int i=1;i<=11;i++)
    {
        cout<<"deg+ "<<i<<": "<<ra[i]<<endl;
    }
    for(int i=1;i<=11;i++)
    {
        cout<<"deg- "<<i<<": "<<vao[i]<<endl;
    }
}
