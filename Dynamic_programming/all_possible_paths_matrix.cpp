#include<bits/stdc++.h>
using namespace std;
long long int no_of_paths(int r,int c,int R,int C,vector<vector<int>>&dp)
{
        if(r==0 && c==0)
        return 1;
        
        if(r < 0 || c < 0)
        return 0;
        
        if(dp[r][c] != -1)
        return dp[r][c];
        // cout<<"solving "<<r<<" "<<c<<endl;
        
        long long int  up=0;
        long long int  left=0;
        
        if(r-1 >= 0)
        up=no_of_paths(r-1,c,R,C,dp);

        if(c-1 >= 0)
        left=no_of_paths(r,c-1,R,C,dp);
        
        // cout<<up<<" "<<left<<" "<<endl;
        return dp[r][c]=up+left;
        
}

int tabulation(int n,int m)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    dp[0][0]=1;

    for(int i=0;i<n;i++)
    dp[i][0]=1;

    for(int j=0;j<m;j++)
    dp[0][j]=1;

    for(int i=1;i < n;i++)
    {
        for(int j=1;j<m;j++)

        {
            dp[i][j]=dp[i][j-1] + dp[i-1][j];
        }
    }

        return dp[n-1][m-1];

}

int spaceOptimization(int n,int m)
{

         vector<int>col(m,0);
            col[0]=1;
         for(int i=0;i<n;i++)
         {
            for(int j=1;j<m;j++)
            {
                if(i==0)
                {
                    col[j]=col[j-1];
                }
           
                else{
                    col[j]=col[j]+col[j-1];
                }


            }
          

         }
    return col[m-1];
}

int main()
{
    int n,m;
    cin>>n>>m;


cout<<spaceOptimization(n,m);

    //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

   // cout<<no_of_paths(n-1,m-1,n,m,dp);

    
}