#include<bits/stdc++.h>
using namespace std;

int max_chocolate(int row,int c1,int c2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp,int R,int C)
{

        if(c1 < 0 || c1 >=C || c2 >= C || c2 < 0)
        return 0;

        if(row==R-1)
        {
            if(c2==c1)
            return grid[row][c1];

            return  grid[row][c1]+grid[row][c2];
        }

        int ans=0;
        int maxi=0;

        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int value=0;
                if(c1 !=c2)
                    value=grid[row][c1]+grid[row][c2];
                else
                    value=grid[row][c1];
                
               maxi=max(maxi,value+max_chocolate(row+1,c1+i,c2+j,grid,dp,R,C));

            }
        }
        return maxi;

}

void tabulation(int n,int m,vector<vector<int>>&grid)
{

    int c=m;

vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

for(int col1=0;col1<m;col1++)
{
    for(int col2=0;col2<m;col2++)
    {
        if(col1==col2)
        dp[n-1][col1][col2]=grid[n-1][col1];

        else dp[n-1][col1][col2]=grid[n-1][col1]+ grid[n-1][col2];
    }
}
cout<<"reached here"<<endl;

for(int row=n-2;row >=0;row--)
{
    for(int c1=0;c1<m;c1++)
    {
        for(int c2=0;c2<m;c2++)
        {
            int maxi=0;
            for( int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++)
            {
                int nc1=c1+i;
                int nc2=c2+j;

                if( nc1 < 0 || nc1 > m || nc2 < 0 || nc2 > m)
                continue;

                maxi=max(maxi,dp[row+1][nc1][nc2]);

            }
            }

            if(c1== c2)
            dp[row][c1][c2]=maxi+grid[row][c1];
            else
            dp[row][c1][c2]=maxi+grid[row][c1]+grid[row][c2];

        }
    }
}
cout<<dp[0][0][0];
}

int main()
{

int n,m;
cin>>n>>m;

vector<vector<int>>grid(n,vector<int>(m));

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>grid[i][j];
    }
}

tabulation(n,m,grid);

vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    cout<< max_chocolate(0,0,m-1,grid,dp,n,m);

 return 0;
}