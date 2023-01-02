#include<bits/stdc++.h>
using namespace std;
int l=1e8;
int min_edits(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
{
            if(i<0)
            return  j+1;    //insert the remaining string

            if(j< 0)
            return i+1;   // delete the remaining string

            if(dp[i][j] !=-1)
            return dp[i][j];

            int cnt1=l,cnt2=l,cnt3=l,cnt4=l;
            if(s1[i]==s2[j])
            {
                // matche to reduce both by one
                cnt1=0+min_edits(i-1,j-1,s1,s2,dp);
                // matches but i stil want to try using delete option
                cnt2=1+min_edits(i-1,j,s1,s2,dp);
            }
            else{
                //tryint uisng delete
                cnt2=1+ min_edits(i-1,j,s1,s2,dp);
                // using insert
                cnt3=1+min_edits(i,j-1,s1,s2,dp);
                // using replace
                cnt4=1+min_edits(i-1,j-1,s1,s2,dp);
            }

            return dp[i][j]=min(cnt1,min(cnt2,min(cnt3,cnt4)));
}

int min_edits_tabulation(string s1,string s2)
{
    int n=s1.size();
    int m=s2.size();
vector<vector<int>>dp(n+1,vector<int>(m+1));

    for(int i=0;i<=m;i++)
    dp[0][i]=i;
    
    for(int i=0;i<=n;i++)
    dp[i][0]=i;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
             int cnt1=l,cnt2=l,cnt3=l,cnt4=l;
            if(s1[i-1]==s2[j-1])
            {
                // matche to reduce both by one
                cnt1=0+dp[i-1][j-1];
                // matches but i stil want to try using delete option
                cnt2=1+dp[i-1][j];
            }
            else{
                //tryint uisng delete
                cnt2=1+ dp[i-1][j];
                // using insert
                cnt3=1+dp[i][j];
                // using replace
                cnt4=1+dp[i-1][j-1];
            }

             dp[i][j]=min(cnt1,min(cnt2,min(cnt3,cnt4)));
        }
    }
    return dp[n][m];

}

int main()
{


string s1,s2;
cin>>s1>>s2;
int n=s1.length();
int m=s2.length();
cout<<min_edits_tabulation(s1,s2);
vector<vector<int>>dp(n,vector<int>(m,-1));
cout<< min_edits(n-1,m-1,s1,s2,dp);

// return min_edits(n-1,m-1,s1,s2);


 return 0;
}