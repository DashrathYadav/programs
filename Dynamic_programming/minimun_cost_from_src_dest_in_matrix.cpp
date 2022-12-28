#include<bits/stdc++.h>
using namespace std;


int min_cost(vector<vector<int>>matrix,int r,int c,int n,int m,vector<vector<int>>dp)
{

          
            if(r==n-1 && c==m-1)
            {
                return matrix[r][c];
            }
            if(dp[r][c] != -1)
            return dp[r][c];


            int c1=1e5;
            int c2=1e5;

            if(c+1 < m)
            c1=min_cost(matrix,r,c+1,n,m,dp);

            if(r+1 <n)
            c2=min_cost(matrix,r+1,c,n,m,dp);

            return dp[r][c]= min(c1,c2)+matrix[r][c];

}


void min_cost_using_dp_tabulation(vector<vector<int>>matrix,int n,int m)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    dp[n-1][m-1]=matrix[n-1][m-1];

    for(int i=n-2;i>=0;i--)
    dp[i][m-1]=matrix[i][m-1]+dp[i+1][m-1];

    for(int i=m-2;i>=0;i--)
    dp[n-1][i]=matrix[n-1][i]+dp[n-1][i+1];


    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
                if(j==m-1 && i== n-1)
                {
                    dp[i][j]=matrix[i][j];
                }
                else
            dp[i][j]=min(dp[i+1][j],dp[i][j+1])+matrix[i][j];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{


int n,m;
cin>>n>>m;
vector<vector<int>>matrix(n,vector<int>(m));
vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>matrix[i][j];
    }
}

    //cout<<min_cost(matrix,0,0,n,m,dp);

   min_cost_using_dp_tabulation(matrix,n,m);

 return 0;
}