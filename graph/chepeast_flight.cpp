//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        int N =flights.size();
        int k=K+1;
         vector<pair<int,int>>adj[n];

         for(int i=0;i<N;i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<int>cost(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,k});
        cost[src]=0;

        // for(auto it: adj)
        // {
        //     for(auto i : it)
        //     cout<<i.first<<" "<<i.second<<"   ";

        // }
        // cout<<endl;
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
         //   cout<<node.first<<" "<<node.second<<endl;            
            for(auto it: adj[node.first])
            {
               // cout<<it.second<<" "<<cost[node.first]<<" "<<cost[it.first]<<endl;
                if( it.second + cost[node.first] < cost[it.first]  && node.second > 0)
                {
                    

                    q.push({it.first,node.second-1});
                    
                    cost[it.first]=cost[node.first]+it.second;
                }
            }
        }
//         for(int i=0;i<n;i++)
//         cout<<cost[i]<<" ";
//         cout<<endl;
// cout<<cost[dst];
// cout<<endl;
return cost[dst];

    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends