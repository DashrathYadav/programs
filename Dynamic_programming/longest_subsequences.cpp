#include<bits/stdc++.h>
using namespace std;

int longest_subsequence(int i1,int i2,string s1,string s2,vector<vector<int>>&dp)
{
    
    if(i1 < 0 || i2 < 0)
    return 0;

        if(dp[i1][i2] !=-1)
        return dp[i1][i2];

         if(s1[i1]==s2[i2])
         return  dp[i1][i2]= 1 + longest_subsequence(i1-1,i2-1,s1,s2,dp);

         return dp[i1][i2]= max(longest_subsequence(i1-1,i2,s1,s2,dp),longest_subsequence(i1,i2-1,s1,s2,dp));
}

    
    int tabulation(int x,int y,string s1,string s2)
    {
         vector<vector<int >>dp(x+2,vector<int>(y+2,0));
         

         for(int i=1;i<=x;i++)
         {
             for(int j=1;j<=y;j++)
             {
                 
                  if(s1[i-1]==s2[j-1])
           dp[i][j]= 1 + dp[i-1][j-1];
        
            else
             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

             }
         }
    
         
         return dp[x][y];
    }
    


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string s=s1;
    string t=s2;
    vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));

    cout<<longest_subsequence(s1.size()-1,s2.size()-1,s1,s2,dp);

     string S;
    //  for(int i=0;i<dp[s.size()-1][t.size()-1];i++)
    //  {
    
    //  }
        
    int i=s.size()-1;
    int j=t.size()-1;
    while(i >0 && j >0)
        {
             if(s[i]==t[j])
             {
                S+=s[i];
                i--;
                j--;
             }
             else{
                     
                    
                    if(dp[i-1][j] >= dp[i][j-1])
                    i--;

                    else j--;                     
                       

             }
        }
        if(s[i]==t[j])
        S+=s[i];

        reverse(S.begin(),S.end());


        cout<<S<<endl;
    }

