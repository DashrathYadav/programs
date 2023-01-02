// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:

   string printing_longest_comman_supersequences(string &s1,string &s2,vector<vector<int>>&dp)
    {
        int n=s1.length();
        int m=s2.length();

        int i=n;
        int j=m;
        string s="";
        while(i> 0 && j > 0)
        {
             if( s1[i-1]==s2[j-1])
             {
                
                s+=s1[i-1];
                i--;
                j--;
                
             }
             else{

                    if(dp[i-1][j]==dp[i][j])
                    {
                        s+=s1[i-1];
                        i--;
                    }
                    else if(dp[i][j-1]==dp[i][j])
                    {
                        s+=s2[j-1];
                        j--;
                    }
                    else{
                        break;
                    }
             }
        }
      
      if( i !=0 && j==0)
      {
         while(i--)
         s+=s1[i];
      }
      
      if( i ==0 && j!=0)
      {
         while(j--)
         s+=s2[j];
      }

            reverse(s.begin(),s.end());
        cout<<s<<endl;

    }

    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        
        for(int i=0;i<=n;i++)
        dp[0][i]=0;
        for(int i=0;i<=m;i++)
        dp[i][0]=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        printing_longest_comman_supersequences(x,y,dp);
        
        return  m+n-dp[m][n];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends