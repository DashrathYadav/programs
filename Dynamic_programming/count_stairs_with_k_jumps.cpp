/*
Count no of ways to reach nth stairs
 if from one stairs you can  jump up to k  stairs from current stairs
 */

#include<bits/stdc++.h>
using namespace std;


int main()
{
int n,k;
cin>>n>>k;

 vector<int>stair(n+1);
 stair[0]=1;
 stair[1]=1;

  
 for(int i=2;i<=n;i++)
 {
      int stair_count=0;

    for(int j=1;j<=k;j++)
    {
        if(i-j >=0)
        {
            stair_count+=stair[i-j];
        }
        stair[i]=stair_count;

    }
 }

 for(auto it: stair)
 cout<<it<<" ";
 cout<<endl;

cout<<stair[n]<<endl;



 return 0;
}