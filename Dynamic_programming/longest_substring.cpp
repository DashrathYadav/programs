
#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,m;
    cin>>n>>m;
    string s1;
    string s2;

    cin>>s1>>s2;


    vector<vector<int>>dp(n+2,vector<int>(m+2,0));

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;

    }

    int maxi=0;
    for(int r=1;r<=n;r++)
    {
        for(int c=1;c<=m;c++)
        {

            if(s1[r-1] ==s2[c-1])
            {
                dp[r][c]=1+dp[r-1][c-1];
                maxi=max(maxi,dp[r][c]);
            }
            else{
                dp[r][c]=0;
            }

        }
    }
    cout<<maxi<<endl;
    return maxi;

}