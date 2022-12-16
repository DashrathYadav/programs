//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
  public:

    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int m=1e5;
        start=start%m;
        queue<ll>q;
        q.push(start);
      vector<int>hash(m,0);
        hash[start]=1;
        int cnt=0;
        while(!q.empty())
        {
           

            int s=q.size();
            while(s--)
            {
                 ll a=q.front();
            q.pop();
            if(a== end)
            return cnt;

            for(auto it : arr)
            {
                ll new_val=(it*a);
                 if(new_val==end)
                return cnt+1;
                if(new_val >=m)
                new_val%=m;
                if(new_val==end)
                return cnt+1;
                if(hash[new_val]==0)
               { q.push(new_val);
               hash[new_val]=1;
               }
            }
            }
            cnt++;

        }
        return -1;
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends