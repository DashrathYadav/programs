#include<bits/stdc++.h>
using namespace std;


int adjacent_sum(int indx,vector<int>&v,int n,vector<int>&dp)
{
    if(indx==n-1)
    return v[n-1];

    if(indx >=n)
    return 0;

if(dp[indx] != -1)
return dp[indx];

    int sum1=0;
    int sum2=0;

 
              sum1= v[indx]+ adjacent_sum(indx+2,v,n,dp);
             sum2=adjacent_sum(indx+1,v,n,dp);
        

      return dp[indx]=max(sum1,sum2);
    
}

// space optimization;
void tablation(int n,vector<int>&v)
{
   int  last=v[n-1];
   int second_last=max(v[n-1],v[n-2]);
  int newlast;
    for(int i=n-3;i>=0;i--)
    {

        newlast=max(last+v[i],second_last);
        last=second_last;
        second_last=newlast;
    }
cout<<newlast;
    
}

int main()
{

for(int i=0;i<6;i++)
{
    int n;
    cin>>n;
vector<int>v(n);
vector<int>dp(n,-1);
vector<int>dp1(n,-1);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

int ans= max( adjacent_sum(0,v,n-1,dp), adjacent_sum(1,v,n,dp1));
   cout<< ans<<endl;
}
   cout<<endl;
  // tablation(n,v);


 return 0;
}