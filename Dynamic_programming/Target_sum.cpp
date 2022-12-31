/*
https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos*/

#include<bits/stdc++.h>
using namespace std;

 int count_target_sum(int indx,vector<int>&arr,int target,map<pair<int,int>,int>&mp)
  {
           
           if(indx < 0)
           {
            if(target==0)
            return 1;

            return 0;
           }

                auto it=mp.find({indx,target});
           if( it !=mp.end() )
           return  it->second;

            int ncount=0;
            int pcount=0;
             //negative take
            ncount=count_target_sum(indx-1,arr,target+arr[indx],mp);

            //positivel take
           pcount= count_target_sum(indx-1,arr,target-arr[indx],mp);

           return mp[{indx,target}]= pcount+ncount;

 }

int main()
{
map<pair<int,int>,int>mp;
int n,t;
cin>>n>>t;
int target=t;
vector<int>arr(n);

for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
   cout<< count_target_sum(n-1,arr,target,mp);


 return 0;
}