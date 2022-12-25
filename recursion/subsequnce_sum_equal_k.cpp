#include<bits/stdc++.h>
using namespace std;

void subsequences(vector<int>arr,int n,int sum,vector<int>&d,vector<vector<int>>&ans)
{
    if(n<0)
    {
        if(sum==0)
        ans.push_back(d);

        return;
    }
    if(sum==0)
    {
        ans.push_back(d);
        return;
    }

    if( (sum - arr[n]) >= 0)
    {   d.push_back(arr[n]);
        subsequences(arr,n-1,sum-arr[n],d,ans);
        d.pop_back();
    }
    subsequences(arr,n-1,sum,d,ans);
}


int main()
{
int n;
cin>>n;
vector<int>arr(n,0);
for(int i=0;i<n;i++)
cin>>arr[i];
vector<int>d;
vector<vector<int>>ans;

for(int i=0;i<n;i++)
cout<<arr[i]<<' ';
cout<<endl;

subsequences(arr,n-1,4,d,ans);
cout<<ans.size()<<endl;
for(int i=0;i<ans.size();i++)
{
    for(int j=0;j<ans[i].size();j++)
    {
        cout<<ans[i][j];
    }
    cout<<endl;
}

 return 0;
}