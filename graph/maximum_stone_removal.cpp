//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class DisjointSet
{
    public:
    vector<int> size, parent;
    int N;

    DisjointSet(int n)
    {
        N=n;
        size.resize(N + 1,1);
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        int r=0,c=0;
        for(int i=0;i<n;i++)
        {
            int x=stones[i][0];
            int y=stones[i][1];
            
            if(x > r)
            r=x;
            
            if(y > c)
            c=y;
        }
    
        cout<<r<<' '<<c<<endl;
        int N=r+c+1;
           DisjointSet ds=DisjointSet(N);

        
        for(int i=0;i<n;i++)
        {
             int x=stones[i][0];
            int y=stones[i][1]+r+1;
            ds.parent[x]=x;
            ds.parent[y]=y;
                ds.UnionBySize(x,y);
        }

        for(int i=0;i<ds.parent.size();i++)
        {
            cout<<ds.parent[i]<<" ";
        }

    
    }
      
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends