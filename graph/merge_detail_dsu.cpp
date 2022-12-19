//{ Driver Code Starts
// Initial Template for C++

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
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        // code here
        int n=details.size();
        DisjointSet ds(n);
        map<string,int>mapMailNode;

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<details[i].size();j++)
            {
                    string mail=details[i][j];
                    if( mapMailNode.find(mail) ==mapMailNode.end())
                    mapMailNode[mail]=i;
                    else{
                       int  node=mapMailNode[mail];
                        ds.UnionBySize(node,i);
                    }

            }
        }
        vector<string>MergeMails[n];

        for(auto it :mapMailNode)
        {
            int node=ds.findParent(it.second);
            string str=it.first;
            MergeMails[node].push_back(str);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++)
        {
            int s=MergeMails[i].size();
            if(s==0)
            continue;

            vector<string>detail;
            detail.push_back(details[i][0]);
            sort(MergeMails[i].begin(),MergeMails[i].end());
            
            for(auto it : MergeMails[i])
            detail.push_back(it);

            ans.push_back(detail);


        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends