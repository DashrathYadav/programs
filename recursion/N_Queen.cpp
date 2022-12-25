
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

        bool check(vector<string>&board,int n,int lev,int col)
        {
                for(int i=0;i<lev;i++)
                {
                    if(board[i][col]=='Q')
                    return false;
                }

                for(int i=lev,j=col;(i >= 0 && j >= 0);i--,j--)
                {
                    if(board[i][j]=='Q')
                    return false;
                }
                
                 for(int i=lev,j=col;(i >= 0 && j < n);i--,j++)
                {
                    if(board[i][j]=='Q')
                    return false;
                }
            return true;


        }
    void placeQueen(vector<vector<string>>&boards,vector<string>&board,int n,int lev)
    {
            if(lev >=n)
            {
                boards.push_back(board);
                return;
            }

            for(int col=0;col<n;col++)
            {
                if(check(board,n,lev,col))
                {
                    board[lev][col]='Q';
                    placeQueen(boards,board,n,lev+1);
                    board[lev][col]='.';
                }
            }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>boards;
        string str;
        for(int i=0;i<n;i++)
            str+='.';

        vector<string>board(n,str);
        placeQueen(boards,board,n,0);
        return boards;

    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    s.solveNQueens(n);

    // if u want to see solution u can print 
    // is solution of all possible ans that can form;

}