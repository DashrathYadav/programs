//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet
{
    vector<int> size, parent;
    int N;
public:
    DisjointSet(int n)
    {
        N=n;
        size.resize(N + 1,1);
        parent.resize(N + 1);

        for (int i = 0; i <= N; i++)
            parent[i] = i;
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
    int Solve(int n, vector<vector<int>>& edge) {
        
		DisjointSet U(n);
int cnt=0;  // to count no of edges that are alredy a part of component 
			//but reappera so we count it to make diconnected node connected  
  for(auto it: edge)
  {
	int u=it[0];
	int v=it[1];
	if(U.findParent(u)==U.findParent(v))
	cnt++;

	U.UnionBySize(u,v);


  }      
 set<int>s;
  for(int i=0;i<n;i++)
  {
	s.insert(U.findParent(i));
  }

  int disconnected_component=s.size()-1;
  
  if(cnt < disconnected_component)
  return -1;

  return disconnected_component;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends