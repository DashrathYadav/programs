/* 
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
4. You are standing in the top-left corner and have to reach the bottom-right corner. 
Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.

Note1 -> Please check the sample input and output for details
Note2 -> If all four moves are available make moves in the order 't', 'l', 'd' and 'r'
Input Format
A number n
A number m
e11
e12..
e21
e22..
.. n * m number of elements
Output Format
trrrdlt
tlldrt
.. and so on
Question Video

  COMMENTConstraints
1 <= n <= 10
1 <= m <= 10
e1, e2, .. n * m elements belongs to set (0, 1)
Sample Input
3 3
0 0 0
1 0 1
0 0 0
Sample Output
rddr

*/

#include<bits/stdc++.h>
using namespace std;


void maze_solver(vector<vector<int>>maze,int r,int c,int n,int m,string d,vector<vector<int>>&v)
{
        if(r < 0 || r >=n || c<0 || c>=m || maze[r][c]==1)
        return;

        if(r==n-1 && c==m-1)
        {
            cout<<d<<endl;
            return;
        }

        if(!v[r][c])
            {   v[r][c]=1;
                maze_solver(maze,r-1,c,n,m,d+'t',v);
                v[r][c]=0;
            }

        if(!v[r][c]){
             v[r][c]=1;
        maze_solver(maze,r+1,c,n,m,d+'d',v);
         v[r][c]=0;
        }
        if(!v[r][c])
        {
             v[r][c]=1;
        maze_solver(maze,r,c-1,n,m,d+'l',v);
         v[r][c]=0;
        }
        if(!v[r][c]){
         v[r][c]=1;
        maze_solver(maze,r,c+1,n,m,d+'r',v);
         v[r][c]=0;
        }

}

//more optmised
void maze_solver2(vector<vector<int>>maze,int r,int c,int n,int m,string d,vector<vector<int>>&v)
{
        if(r < 0 || r >=n || c<0 || c>=m || maze[r][c]==1 || v[r][c])
        return;

        if(r==n-1 && c==m-1)
        {
            cout<<d<<endl;
            return;
        }
            v[r][c]=1;
        maze_solver(maze,r-1,c,n,m,d+'t',v);
        maze_solver(maze,r+1,c,n,m,d+'d',v);
        maze_solver(maze,r,c-1,n,m,d+'l',v);
        maze_solver(maze,r,c+1,n,m,d+'r',v);

        v[r][c]=0;
}






int main()
{

int n,m;
cin>>n>>m;

vector<vector<int>>maze(n,vector<int>(m,0));
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    cin>>maze[i][j];
}
vector<vector<int>>v(n,vector<int>(m,0));
maze_solver2(maze,0,0,n,m,"",v);
 return 0;
}