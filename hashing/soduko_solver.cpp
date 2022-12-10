#include <bits/stdc++.h>
using namespace std;

void helper(int r, int c, vector<vector<int>>&soduko, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> row, vector<map<int, int>> col)
{
            if (r == 9)
            {
                for (auto it : soduko)
                {
                    for (auto i : it)
                    {
                        cout << i << " ";
                    }
                    cout << endl;
                }
                cout << endl;

                return;
            }

        if(c==9)
        {
            helper(r+1,0,soduko,mp,row,col);
            return;
        }


        if(soduko[r][c]!=0)
        {
        helper(r,c+1,soduko,mp,row,col);
        return;
        }

        for(int i=1;i<=9;i++)
        {
            int rw=r/3,cl=c/3;
            if((!mp[{rw,cl}][i]) and (!row[r][i]) and (!col[c][i]) )
            {
                mp[{rw,cl}][i]=1;
                row[r][i]=1;
                col[c][i]=1;
                soduko[r][c]=i;
                helper(r,c+1,soduko,mp,row,col);
                 mp[{rw,cl}][i]=0;
                row[r][i]=0;
                col[c][i]=0;
                soduko[r][c]=0;
                

            }
        }


}

void soduko_solver(vector<vector<int>> &soduko)
{
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (soduko[i][j]!=0)
            {
                mp[{i / 3, j / 3}][soduko[i][j]] = 1;
                row[i][soduko[i][j]] = 1;
                col[j][soduko[i][j]] = 1;
            }
        }
    }
    helper(0,0,soduko,mp,row,col);
}

int main()
{
    vector<vector<int>> soduko = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                  {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                  {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                  {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                  {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                  {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                  {0, 0, 5, 2, 0, 6, 3, 0, 0}};

      soduko_solver(soduko);

    //    for (auto it : soduko)
    //             {
    //                 for (auto i : it)
    //                 {
    //                     cout << i << " ";
    //                 }
    //                 cout << endl;
    //             }
    //             cout << endl;
      
      return 0;

}