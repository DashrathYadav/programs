//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class DisjointSet
{

    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void UnionByRank(int u, int v)
    {

        int sp_u = findParent(u);
        int sp_v = findParent(v);

        if (rank[sp_u] < rank[sp_v])
        {
            parent[sp_u] = sp_v;
        }
        else if (rank[sp_u] > rank[sp_v])
        {
            parent[sp_v] = sp_u;
        }
        else
        {
            parent[sp_v] = sp_u;
            rank[sp_u]++;
        }
    }
};



// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                pq.push({it[1],{i,it[0]}});
            }
        }
        DisjointSet s= DisjointSet(V);
      
        cout<<endl;
        int sum=0;
        while (!pq.empty())
        {
            pair<int,pair<int,int>>node=pq.top();
            pq.pop();

            if(s.findParent(node.second.first)==s.findParent(node.second.second))
            continue;

            s.UnionByRank(node.second.first,node.second.second);
         
            sum+=node.first;
        }
      
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends