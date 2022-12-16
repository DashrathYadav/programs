//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// c
class Solution {
  public:

int num=1e8;


    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        K+=1;
          pair<int,pair<int,int>>p;
          p.first=0;
          p.second.first=K;
          p.second.second=src;

        vector<pair<int,int>>adj[n];
        int N=flights.size();
        for(int i=0;i<N;i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
       vector<int>v(n,1e8);
        v[src]=0;

            queue<pair<int,pair<int,int>>>pq;
            pq.push(p);
            while(!pq.empty())
            {
                pair<int,pair<int,int>>np=pq.front();
                pq.pop();
              
                if(np.second.first <=0) 
                continue;

                for(auto it : adj[np.second.second])
                {
                    int cost=it.second+v[np.second.second];
                  //  cout<<v[it.first]<<endl;
                   v[it.first]=min(cost,v[it.first]);

                 //  cout<<cost<<endl;
                 

                    pq.push({v[it.first],{np.second.first-1,it.first}});

                }

                
            }
            // for(auto it: v )
            // cout<<it<<' ';

            //cout<<endl;
            if(v[dst]==num)
        return -1;
        return v[dst];
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