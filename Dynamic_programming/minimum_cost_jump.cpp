/*Given an array of N integers arr[] where each element represents the max length of the jump that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to the last. 
Example 2:

Input :
N = 6
arr = {1, 4, 3, 2, 6, 7}
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element.

Your task:
You don't need to read input or print anything. Your task is to complete function minJumps() which takes the array arr and it's size N as input parameters and returns the minimum number of jumps. If not possible return -1.


Expected Time Complexity: O(N)
Expected Space Complexity: O(1)


Constraints:
1 ≤ N ≤ 107
0 ≤ arri ≤ 107
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:

            
         int min_cost(int indx,int arr[],int n,vector<int>&dp)
         {

                if(indx >= n-1)
                return 0;

                if(dp[indx]!=-1)
                return dp[indx];

                int mini=1e8;
                for(int i=1;i<=arr[indx];i++)
                {
                    mini=min(mini,min_cost(indx+i,arr,n,dp));
                }

                return dp[indx]= mini+1;
         }

    int minJumps(int arr[], int n){
        
        // Your code here
        vector<int>dp(n+1,-1);

        if(arr[0]==0)
        return -1;

      // int ans= min_cost(0,arr,n,dp);
    //    if(ans >=1e8)
    //    return -1;
    //    else 
    //    return ans;



      // using tabulation method


            dp[n]=0;

            for(int i=n-1;i>=0;i--)
            {
                int min_cost=INT_MAX;

                for(int j=1;j<=arr[i] && j+i <= n;j++)
                {
                    if(dp[i+j] !=-1)
                     min_cost=min(min_cost,dp[i+j]);
                }

                    if(min_cost !=INT_MAX)
                dp[i]=min_cost+1;




            }

        return dp[0];
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends