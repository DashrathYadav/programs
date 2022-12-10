#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        mp[sum]++;
    }
    map<int,int>:: iterator it;
    int ans=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        ans=ans+(((it->second)*(it->second-1))/2);

        if(it->first==0)
        ans=ans+it->second;
    }
    cout<<ans<<endl;

}