//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<int>dis(n,INT_MAX);
        vector<int>count(n,0);
        count[0]=1;
        dis[0]=0;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<pair<int,int>>pq;
        pq.insert({0,0});

          vector<pair<int,int>>adj[n];
        int N=roads.size();
        
        for(int i=0;i<N;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }

        while(!pq.empty())
        {
            
            pair<int,int>p = *(pq.begin());
            pq.erase(pq.begin());
            
          //  cout<<p.first<<" "<<p.second<<endl;

        //       for(auto it : count)
        // cout<<it<<" ";
        // cout<<endl;
            for(auto it : adj[p.second])
            {
                int cost=it.second+p.first;
                if(cost <= dis[it.first] ){
                    dis[it.first]=cost;
                  //  cout<<p.first<<" "<<p.second<<" "<<it.second<<" "<<it.first<<endl;
                    count[it.first]=count[it.first]+count[p.second];
                  //  cout<<count[it.first]<<" "<<count[p.second]<<endl;
                    
                    pq.insert({cost,it.first});
                }
            }

        }
        // for(auto it : count)
        // cout<<it<<" ";
        // cout<<endl;

        return count[n-1];



    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends