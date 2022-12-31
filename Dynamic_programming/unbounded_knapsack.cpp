#include<bits/stdc++.h>
using namespace std;

int max_profit(int indx,int w,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp)
{
        
        if(w==0)
        return 0;

        if(indx==0)
        {
            if(wt[0] <= w)
            return val[0];

            return 0;
        }
        
        int take=0;
        int nottake=0;

        // nottake
        nottake=max_profit(indx-1,w,wt,val,dp);

        //take
        if(wt[indx] <=w)
        take=val[indx]+max_profit(indx,w-wt[indx],wt,val,dp);

        return max(take,nottake);
}

int tabulation(int n,int W,vector<int>&wt,vector<int>&val)
{

vector<vector<int>>dp(n,vector<int>(W+1,0));

for(int i=0;i<n;i++)
 dp[i][0]==0;

 for(int i=0;i<=W;i++)
 {
      if(wt[0] <= W)
        dp[0][i]=val[0];
 }

 for(int i=1;i<n;i++)
 {
    for(int w=1;w<=W;w++)
    {
         int take=0;
        int nottake=0;

        // nottake
        nottake= dp[i-1][w];

        //take
        if(wt[i] <=w)
        take=val[i]+dp[i][w-wt[i]];

          dp[i][w]= max(take,nottake);


    }
 }

 return dp[n-1][W];

}


int main()
{

int n;
cin>>n;
int w;
cin>>w;
vector<int>val(n);
vector<int>wt(n);
for(int i=0;i<n;i++)
cin>>val[i];

for(int i=0;i<n;i++)
cin>>wt[i];
int W=w;
vector<vector<int>>dp(n,vector<int>(W+1,-1));
    cout<<max_profit(n-1,w,wt,val,dp);
    // return tabulation(n,w,wt,val);


 return 0;
}