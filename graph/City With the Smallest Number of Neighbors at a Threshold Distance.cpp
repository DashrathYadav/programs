//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) 
        {
            int d=distanceThreshold;
            vector<vector<int>>matrix(n,vector<int>(n,1e8));
            for(auto it: edges)
            {
                
                matrix[it[0]][it[1]]=it[2];
                matrix[it[1]][it[0]]=it[2];
                
            }
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            if(j==i)
            matrix[i][j]=0;
            
            for(int vai=0;vai<n;vai++)
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]=min(matrix[i][j],matrix[i][vai]+matrix[vai][j]);
                }
            }
            
            int cnt;
            int maxi=INT_MAX;
            int city;
              for(int i=0;i<n;i++)
            {   cnt=0;
                for(int j=0;j<n;j++)
                {
                    if ( matrix[i][j] <= d)
                    cnt++;
                }
                if(cnt <= maxi)
                { 
                    maxi=cnt;
                    city=i;
                }
            }
            
           
            
          return city;
            
//             5 6
// 0 1 2
// 0 4 8
// 1 2 3
// 1 4 2
// 2 3 1
// 3 4 1
// 2
// ans=0th city        
            
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends