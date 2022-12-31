//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
  public:
  
  int maximum_cost(int indx,int target,int price[],vector<vector<int>>&dp)
  {
            if(target==0)
            return 0;
            
            if(indx <= 0)
            return 0;
            
            if( dp[indx][target] !=-1)
            return dp[indx][target];
            
            int take=0;
            int nottake=0;
            
            // nottake
             nottake=maximum_cost(indx-1,target,price,dp);
             
             // take
             if(indx <=target)
             take=price[indx-1]+maximum_cost(indx,target-indx,price,dp);
             
             return dp[indx][target]=max(take,nottake);
  }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return  maximum_cost(n,n,price,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends