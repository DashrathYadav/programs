#include<bits/stdc++.h>
using namespace std;

int tabulation(vector<int>&arr,int k)
{
    int n=arr.size();
    
    vector<vector<int>>dp(n,vector<int>(k+1,0));
 
    

    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<=k;j++)
    //     {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<n;i++)
    {
        for(int target=0;target<=k;target++)
        {
            if(i==0)
            {
                if(target !=0)
                {
                    if(arr[0]==target)
                    dp[i][target]=1;
                    else
                    dp[i][target]=0;
                }
                else if( target==0)
                {
                    if(arr[0]==0)
                    dp[i][target]= 2;
                    else
                    dp[i][target]=1;
                }
            }
            

            else{
            int nonformed=dp[i-1][target];

            int formed=0;
            if(arr[i]<=target)
             formed = dp[i-1][target-arr[i]];

            dp[i][target]=formed+nonformed;  
            }
           
            
        }
    }
    // cout<<endl;

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<=k;j++)
    //     {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
   
   return dp[n-1][k];
   
    
}


int main()
{

int n;
cin>>n;
int k;
cin>>k;
vector<int>arr(n);
for(int i=0;i<n;i++)
{
    cin>>arr[i];

}


cout<< tabulation(arr,k);

vector<vector<bool>>dp(n,vector<bool>(k+1,0));

for(int i=0;i<n;i++)
dp[i][0]==1;

 if(arr[0]<=k)
 dp[0][arr[0]]=1;

for(int row=1;row<n;row++)
{
    for(int target=1;target<=k;target++)
    {
            bool nottake=dp[row-1][target];

            bool take=0;
            if(arr[row]<=target)
            {
                 // searching what is required is prresent to complish the target that is take condition
                 if( dp[row-1][target-arr[row]])
                 take=1;
            }

            dp[row][target]= nottake || take ;
    }
}
 
 
 return dp[n-1][k];


}