#include <bits/stdc++.h>
using namespace std;

int ways_count(int n, vector<int> arr, int X, vector<vector<int>> &dp)
{

        if( X < 0)
        return 0;

        if(X==0)
        return 1;

        if(n < 0)
        return 0;
       if(dp[n][X] != -1)
        return dp[n][X];

         int cnt1=0;
         int cnt2=0;

         cnt1=ways_count(n,arr,X-arr[n],dp);
         cnt2=ways_count(n-1,arr,X,dp);

         return dp[n][X]=cnt1+cnt2;

}

int main()
{
    int n,x;
    cin>>n>>x;
vector<int>num(n);
for(int i=0;i<n;i++)
{
    cin>>num[i];
}

    vector<vector<int>> dp(num.size(), vector<int>(x + 1, -1));
    int cnt = ways_count(num.size() - 1, num, x, dp);
   
    cout<<cnt;


}