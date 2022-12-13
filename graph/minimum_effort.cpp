//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {


  public:

 struct node {
        int diff;
        int parent;
        int x;
        int y;
        int val;
        int entry;
    };

    struct mycomp{
        bool operator()(struct node n1,struct node n2)
        {
            return n1.diff > n2.diff;
        }
    };

   

    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int entry=1;
        priority_queue<struct node,vector<struct node>,mycomp>pq;
        int N=heights.size();
        int M=heights[0].size();
        vector<vector<int>>v(N,vector<int>(M,0));
        node n1;
        n1.x=0;
        n1.y=0;
        n1.val=heights[0][0];
        n1.parent=heights[0][0];
        n1.diff=0;
        n1.entry=1;

        pq.push(n1);

            int delx[4]={0,1,0,-1};
            int dely[4]={-1,0,1,0};
            v[0][0]=1;
        struct node n;
        while(!pq.empty())
        {
             n= pq.top();
              v[n.x][n.y]=1;
           //  cout<<" x"<<n.x<<" y"<<n.y<<" val "<<n.val<<" parent "<<n.parent<<" diff "<<n.diff<<"  entry "<< n.entry<<endl;
            pq.pop();
          
            if(n.x==N-1 && n.y==M-1)
            break;

            for(int i=0;i<4;i++)
            {
                int newx=n.x+delx[i];
                int newy=n.y+dely[i];

                if(newx >=0 && newx < N && newy >=0 && newy <M && !v[newx][newy] )
                {
                        node n2;
                        n2.x=newx;
                        n2.y=newy;
                        n2.parent=n.val;
                        n2.val=heights[newx][newy];
                        n2.diff=max(n.diff,abs(n.val - heights[newx][newy]));
                            entry++;
                            n2.entry=entry;
                        pq.push(n2);
                        // v[newx][newy]=1;
                       

                }

            }

        }
     //   cout<<n.diff<<endl;
            return n.diff;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends