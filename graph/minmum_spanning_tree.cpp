//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
    
       
        vector<int>v(V,0);
     
        int sum=0;
        
        int cnt=0;
      priority_queue< pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>>pq;
       
         pq.push({0,0});
       
        while(!pq.empty())
        {
            pair<int,int>node=pq.top();
        
            pq.pop();
        
        if(v[node.second])
        continue;
        
            sum+=node.first;
        
            cnt++;
            
            if(cnt==V)
            break;
            
            v[node.second]=1;
            
            
            for(auto it: adj[node.second])
            {
                if(!v[it[0]])
                pq.push({ it[1],it[0] });
            }
            
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