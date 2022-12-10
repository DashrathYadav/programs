//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here

        vector<pair<int,int>>dist(n+1,{INT_MAX,0});

        vector<pair<int,int>>adj[n+1];

        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});

        }

            set<pair<int,int>>s;
            dist[1]={0,1};
            s.insert({0,1});

            while(!s.empty())
            {
                pair<int,int>p=*s.begin();
                s.erase(s.begin());
                int node=p.second;
                int dis=p.first;

                for(auto it : adj[node])
                {
                    int newdist=it.second+dis;
                    
                    if(newdist < dist[it.first].first)
                    {

                        if( dist[it.first].first != INT_MAX)
                        {
                            s.erase({dist[it.first].first,it.first});
                        }

                        s.insert({newdist,it.first});
                        dist[it.first]={ newdist,node};

                    }

                }

            }
            // cout<<"Reached"<<endl;
            vector<int>ans;

                if(dist[n].first==INT_MAX)
                {
                    ans.push_back(-1);
                    return ans;
                }

            int node=n;
            while(1)
            {
                ans.push_back(n);
                if(n == 1)
                break;

                n=dist[n].second;

                
                
            }

            reverse(ans.begin(),ans.end());
    return ans;


    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends