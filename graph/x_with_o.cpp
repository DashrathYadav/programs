//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here 
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O')
            {q.push({0,i});
            v[0][i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O')
           { q.push({i,0});
            v[i][0]=1;
           }
        }
         for(int i=0;i<m;i++)
        {
            if(mat[n-1][i]=='O')
            {q.push({n-1,i});
            v[n-1][i]=1;
            }
        }
         for(int i=0;i<n;i++)
        {
            if(mat[i][m-1]=='O')
            {q.push({i,m-1});
            v[i][m-1]=1;
            }
        }
        int dirr[]={-1,0,1,0};
        int dirc[]={0,-1,0,1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=r+dirr[i];
                int y=c+dirc[i];

                if(x >=0 && y>=0 && x<n && y < m && mat[x][y]=='O' && !v[x][y])
                {
                    q.push({x,y});
                    v[x][y]=1;
                }

            }

        }
            for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(!v[i][j])
                {
                    mat[i][j]='X';
                }
            }

            return mat;

        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends