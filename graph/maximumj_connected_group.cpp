//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet
{

public:
    vector<int> size, parent;
    int N;

    DisjointSet(int n)
    {
        N=n;
        size.resize(N + 1,0);
        parent.resize(N + 1);

        for (int i = 0; i <= N; i++)
            parent[i] = -1;
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void UnionBySize(int u, int v)
    {

        int sp_u = findParent(u);
        int sp_v = findParent(v);

            if(sp_u==sp_v)
            return ;

        if (size[sp_u] < size[sp_v])
        {
            parent[sp_u] = sp_v;
            size[sp_v]+=size[sp_u];

        }
        else if (size[sp_u] >= size[sp_v])
        {
            parent[sp_v] = sp_u;
            size[sp_u]+=size[sp_v];
        }
        
    }

    void print_size(){

        for(int i=0;i<=N;i++)
        {
            cout<<size[i]<<" ";
        }
        cout<<endl;
    }


void parent_print()
{
    
    for(int i=0;i<=N;i++)
    {
       cout<<findParent(i)<<" ";
    }
    cout<<endl;
}

};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
  int maxi=1;
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        queue<pair<int,int>>q;
        int del[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int del1[2][2]={{-1,0},{0,-1}};
    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
    
                if(grid[i][j]==0)
                {   q.push({i,j});
                    continue;
                }

                int cell=i*m+j;
                ds.parent[cell]=cell;
                ds.size[cell]=1;
               /// cout<<q.size()<<endl;
                for(int k=0;k<2;k++)
                {
                    int x=i+del1[k][0];
                    int y=j+del1[k][1];
                   // cout<<x<<" "<<y<<endl;

                    if( x >=0 && x <n && y >= 0 && y <m && grid[x][y]==1)
                    ds.UnionBySize((x*m)+y,cell);
                }
                    

            }
        }
       // cout<<q.size()<<endl;
        while(!q.empty())
        {
            pair<int,int>node=q.front();
            q.pop();

                 int r=node.first;
                    int c=node.second;
                    set<int>s;
                  
                    int cnt=1;
                    
                for(int i=0;i<4;i++)
                {
                   
                    int x=r+del[i][0];
                    int y=c+del[i][1];

                    if( x >=0 && x <n && y >= 0 && y <m && grid[x][y])
                    s.insert(ds.findParent(x*m+y));
                
                }
                for(auto it:s)
                {
                    cnt+=ds.size[it];
                }
                maxi=max(maxi,cnt);

        }

return maxi;

    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends