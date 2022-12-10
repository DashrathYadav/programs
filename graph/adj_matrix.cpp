#include<bits/stdc++.h>
using namespace std;



 int n=5;

int main()
{
    vector<vector<int>>a(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int m;
    cin>>m;
    int h,k;
    for(int i=0;i<m;i++)
    {
        cin>>h>>k;
        a[h][k]=1;
    }

       for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}