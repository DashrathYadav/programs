#include<bits/stdc++.h>
using namespace std;

int febo(int n,vector<int>&dp)
{
    if(n==0 || n==1)
    return n;

    if(dp[n] !=-1)
    return dp[n];

    return dp[n]=febo(n-1,dp)+febo(n-2,dp);
}


int main()
{
int n;
cin>>n;
vector<int>dp(n+1,-1);

cout<<febo(n,dp);
 return 0;
}