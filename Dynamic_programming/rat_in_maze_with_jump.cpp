/*1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. Complete the body of printMazePath function - without changing signature - to print the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Input Format
A number n
A number m
Output Format
Print paths (one path in each line) in order hinted by Sample output
Question Video

  COMMENTConstraints
0 <= n <= 5
0 <= m <= 5
Sample Input
3
3
Sample Output
h1h1v1v1
h1h1v2
h1v1h1v1
h1v1v1h1
h1v1d1
h1v2h1
h1d1v1
*/

#include<bits/stdc++.h>
using namespace std;


vector<string>get_paths(int r,int c,int k,int n,int m)
{
        if(r==n-1 && c==m-1)
        {
            vector<string>v;
            v.push_back("");
       return v;
        }

vector<string>ans;
        for(int i=1;i<=k;i++)
        {
        
            vector<string>path;
            if(c+i <= m-1)
            {
            path=get_paths(r,c+i,k,n,m);
                for(auto it:path)
                {
                    char ch=i+'0';
                    it=ch+it;
                    it='h'+it;
                    ans.push_back(it);
                }
            path.clear();
            }

            if(r+i <=n-1)
            {
                path=get_paths(r+i,c,k,n,m);
                for(auto it:path)
                {
                       char ch=i+'0';
                    it=ch+it;
                    it='v'+it;
                    ans.push_back(it);
                }
                path.clear();
        }

            if(r+i <= n-1 && c+i <=m-1)
            {
                path=get_paths(r+i,c+i,k,n,m);
                for(auto it:path)
                {
                       char ch=i+'0';
                    it=ch+it;
                    it='d'+it;
                    ans.push_back(it);
                }
                path.clear();
            }
}

    return ans;
}



int main()
{

int n,m,k;
cin>>n>>m>>k;

    vector<string>ans=get_paths(0,0,k,n,m);

    for(auto it: ans)
    cout<<it<<endl;

 return 0;
}