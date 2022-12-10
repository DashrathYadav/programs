//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:

    pair<char,char>figure_out(string s1,string s2)
    {
        char c1;
        char c2;
        int n= min(s1.size(),s2.size());
        for(int i=0;i<n;i++)
        {
            if(s1[i] != s2[i])
            {
                return {s1[i],s2[i]};
            }
        }
        return {'0','0'};
    }

    string findOrder(string dict[], int N, int K) {
        //code here

        unordered_map<char,set<char>>mp;
        bool flag=1;
         queue<char>q;
        for(int i=1;i<N;i++)
        {

            if(dict[i-1] != dict[i])
            {
                pair<char,char> p=figure_out(dict[i-1],dict[i]);
                
                if(p.first !='0' && p.second !='0')
                {
                    cout<<p.first<<" "<<p.second<<endl;
                        mp[p.first].insert(p.second);
                     
                }
                
            }
        }

        int v=mp.size();
        unordered_map<char,int>indegree;

        for( int i=0;i<K;i++)
        {
            indegree['a'+i]=0;
        }

        for(auto it:mp)
        {
            for(auto i: it.second)
            {
                indegree[i]++;
            }
        }

        for(auto it:indegree)
        {
           if(it.second==0)
           q.push(it.first);
        }


       string str;
        while(!q.empty())
        {
            char node= q.front();
            q.pop();
            str+=node;
            for(auto it : mp[node])
            {
                indegree[it]--;
                if(indegree[it] <= 0)
                {
                    q.push(it);
                }
            }
        }
        cout<<str<<endl;
       return str;

    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends