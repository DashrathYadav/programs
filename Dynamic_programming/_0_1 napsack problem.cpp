//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int maxTillNow(int W,int wt[],int val[],int n,vector<vector<int>>&dp)
    {
        if(n < 0)
        return 0;
        
      
        if(dp[n][W] != -1)
        return dp[n][W];
        
        int val1=0;
        int val2=0;
        // Not taking the item.
         val1=maxTillNow(W,wt,val,n-1,dp);
         
         //Taking that item
         if(wt[n]<=W)
         val2= val[n] + maxTillNow(W-wt[n],wt,val,n-1,dp);
        
        return dp[n][W]=max(val1,val2);
    }
   
   int tabulation(int W, int wt[], int val[], int n)
{
            vector<vector<int>>dp(n,vector<int>(W+1,0));
            
      
        
        for(int i=wt[0];i<=W;i++)
        {
            dp[0][i]=val[0];
        }
        
        
   
        
        for(int i=1;i<n;i++)
        {
            for(int w=0;w<=W;w++)
            {
                {
                     int val1=0;
                     int val2=0;
                    
                     val1=dp[i-1][w];
                     
                      if(wt[i]<=w)
                        val2= val[i] + dp[i-1][w-wt[i]];
                        
                        dp[i][w]=max(val1,val2);
                }
                
            }
        }
        
       
        
       
        return dp[n-1][W];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
      return tabulation(W,wt,val,n);
      
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       
       
         return maxTillNow(W,wt,val,n-1,dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends