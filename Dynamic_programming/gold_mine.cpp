/*
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from 
     any row in the left wall.
5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).

goldmine

6. Each cell has a value that is the amount of gold available in the cell.
7. You are required to identify the maximum amount of gold that can be dug out from the mine.
Input Format
A number n
A number m
e11
e12..
e21
e22..
.. n * m number of elements
Output Format
An integer representing Maximum gold available.
Question Video

  COMMENTConstraints
1 <= n <= 10^2
1 <= m <= 10^2
0 <= e1, e2, .. n * m elements <= 1000
Sample Input
6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1
Sample Output
33
*/

#include<bits/stdc++.h>
using namespace std;


int mine_gold(int r,int c,int n,int m,vector<vector<int>>&mine,vector<vector<int>>&dp)
{

        if( r >=n || c >= m || r < 0)
        {
            return 0;
        }

        if(dp[r][c] != -1)
        return dp[r][c];

int max_gold=0;

     int upper_mine=0,lower_mine=0,mid_mine=0;

     upper_mine=mine_gold(r-1,c+1,n,m,mine,dp);
     mid_mine=mine_gold(r,c+1,n,m,mine,dp);
     lower_mine=mine_gold(r+1,c+1,n,m,mine,dp);

        max_gold= max(upper_mine,max(mid_mine,lower_mine));

        return dp[r][c]=max_gold+mine[r][c];
}


 void using_tabulation(int n,int m,vector<vector<int>>&mine)
 {

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int col=m-1;col>=0;col--)
        {
            for(int row=0;row<n;row++)
            {
                if(col== m-1 )
                {
                    dp[row][col]=mine[row][col];
                }

                else if(row==0)
                {
                    dp[row][col]= max(dp[row][col+1],dp[row+1][col+1])+mine[row][col];
                }
                else if(row==n-1)
                {
                    dp[row][col]=max(dp[row][col+1],dp[row-1][col+1])+mine[row][col];
                }

                else{
                    dp[row][col]=max(dp[row][col+1],max(dp[row+1][col+1],dp[row-1][col+1]))+mine[row][col];
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++)
        maxi=max(maxi,dp[i][0]);

        cout<<maxi<<endl;

 }

int main()
{

int n,m;
cin>>n>>m;

vector<vector<int>>dp(n+1,vector<int>(m,-1));
vector<vector<int>>mine(n,vector<int>(m,0));

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>mine[i][j];
    }
}
// for(int i=0;i<n;i++)
// for(int j=0;j<m;j++)
// {
//     cout<<mine[i][j]<< " ";
// }

using_tabulation(n,m,mine);
return 0;
int maxi=INT_MIN;
for(int i=0;i<n;i++)
{
    maxi=max(maxi,mine_gold(i,0,n,m,mine,dp));
}

cout<< maxi;


 return 0;
}