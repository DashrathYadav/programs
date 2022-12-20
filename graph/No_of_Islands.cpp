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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here

        DisjointSet ds((n+1)*(m+1));
        vector<vector<int>>matrix(n,vector<int>(m,0));
        
        vector<int>ans;
        int del[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto it : operators)
        {
            int r=it[0];
            int c=it[1];
           // cout<<r<<" "<<c<<endl;
            if(matrix[r][c]==1)
            {
                ans.push_back(ans.back());
                continue;
            }
            else{
                  int no=r*m+c;
                matrix[r][c]=1;
                ds.size[no]=1;
                ds.parent[no]=no;
                  
                 
                for(int i=0;i<4;i++)
                {
                    int x=r+del[i][0];
                    int y=c+del[i][1];
                    int no1=x*m+y;
                 //   cout<<x<<" "<<y<<endl;
                    if(x >=0 && x <n && y >=0 && y < m && matrix[x][y]==1)
                    {
                        ds.UnionBySize(no,no1);
                    }

                }
                   int joins=0;
                for(int j=0;j<n*m;j++)
                {
                    if(ds.parent[j]==j)
                    {
                        joins++;
                    }
                }
               // cout<<joins<<endl;
                 
                ans.push_back(joins);

            }


        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends