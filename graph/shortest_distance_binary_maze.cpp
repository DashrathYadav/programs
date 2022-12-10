//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

    struct node{
        int dist;
        int x;
        int y;
        int cov;
    };

    struct mycmp{
        bool operator()(struct node n1,struct node n2)
        {
                return n1.cov > n2.cov;
        }
    };

  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int N=grid.size();
        int M=grid[0].size();
        int dis_req=abs(source.first-destination.first)+abs(source.second-destination.second);
        int cov=0;
        priority_queue<struct node,vector<struct node>,mycmp>pq;
        struct node n;
        n.cov=0;
        n.dist=dis_req;
        n.x=source.first;
        n.y=source.second;
        pq.push(n);
        vector<vector<int>>v(N,vector<int>(M,0));
        int delx[4]={1,0,-1,0};
        int dely[5]={0,1,0,-1};

        while(!pq.empty())
        {
            struct node n= pq.top();
            pq.pop();
            
                if(destination.first==n.x && destination.second==n.y)
                return n.cov;

            for(int i=0;i<4;i++)
            {
                int nx=n.x+delx[i];
                int ny=n.y+dely[i];


                    if(nx >=0 &&  nx <N && ny >=0 && ny < M && !v[nx][ny] && grid[nx][ny]==1)
                    {
                       
                        struct node n1;
                        n1.dist=abs(nx-destination.first)+abs(ny-destination.second);
                        n1.x=nx;
                        n1.y=ny;
                        n1.cov=n.cov+1;
                        pq.push(n1);
                    }   


            }


        }

        return -1;
          

        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends