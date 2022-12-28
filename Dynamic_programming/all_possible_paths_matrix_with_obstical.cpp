#include<bits/stdc++.h>
using namespace std;
long long int no_of_paths(int r,int c,int R,int C,vector<vector<int>>&dp,vector<vector<int>>&matrix)
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
        
        if(r-1 >= 0 && matrix[r-1][c] != -1)
        up=no_of_paths(r-1,c,R,C,dp,matrix);

        if(c-1 >= 0 && matrix[r][c-1] != -1)
        left=no_of_paths(r,c-1,R,C,dp,matrix);
        
        // cout<<up<<" "<<left<<" "<<endl;
        return dp[r][c]=up+left;
        
}

int tabulation(int n,int m,vector<vector<int>>&matrix)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));


    for(int i=0;i < n;i++)
    {
        for(int j=0;j<m;j++)
        {
          if(i==0 && j==0){
          dp[i][j]=1;

        }
        else{
          int up=0;
          int left=0;

          if( matrix[i][j] == -1)
          continue;

            if(i>0)
          up=dp[i-1][j];

          if(j >0)
          left=dp[i][j-1];

          dp[i][j]=up+left;

        }
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
    
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;

    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>matrix[i][j];
    }


//cout<<spaceOptimization(n,m);

cout<< tabulation(n,m,matrix)<<endl;
}

    //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

   //cout<<no_of_paths(n-1,m-1,n,m,dp,matrix);

    
}