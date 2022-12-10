#include<bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];        
    // }
  unordered_map<int,int > mp;
  mp[1]=20;
  mp[1001]=19;
  mp[1001]=17;
  unordered_map<int ,int> :: iterator it;
  for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
  cout<<mp.size()<<endl;
  
}