//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int m=1e9+7;
  int shortest_min=-1;
    void dfs( int src,int min,int *cnt,int end,vector<pair<int,int>>adj[],vector<int>&v)
    {

      //  cout<<" src "<<src<<endl;
       if(shortest_min==-1 && src==end)
       {
            shortest_min=min;
            (*cnt)++;
          //  cout<<" first path "<< shortest_min<<endl;
       }
     
       else if( src==end && min < shortest_min)
       {
       // cout<<"2nd if"<<endl;
        shortest_min=min;
        *cnt=0;
        (*cnt)++;
   // cout<<" updated path "<<shortest_min<<endl;
       }
        else if( min == shortest_min)
        {   
           // cout<<"reached"<<endl;
            // cout<<src<<endl;
            // cout<<end<<endl;
            if(src==end){
            (*cnt)++;
            if(*cnt >=m)
            *cnt=(*cnt)%m;
            // cout<<"here i am"<<endl;
            // cout<<*cnt<<endl;
            return; 
            }
        }
//   cout<<"L"<<endl;
        if( shortest_min !=-1 && min >= shortest_min)
        return;


        v[src]=1;

        for(auto it : adj[src])
        {

          //  cout<<"reached for loop"<<endl;
            if(!v[it.first])
            dfs(it.first,min+it.second,cnt,end,adj,v);



        }

        v[src]=0;
    }
  
  void shortest_path(int n,vector<int>adj[])
  {

  }

    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        vector<pair<int,int>>adj[n];
        int N=roads.size();
        
        for(int i=0;i<N;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }
        
    //    shortest_min= shortest_path(n,adj);
        shortest_min=-1;
        vector<int>v(n,0);
        int min=0;
        int cnt=0;
     dfs(0,min,&cnt,n-1,adj,v);
     
     return cnt;
        
        
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