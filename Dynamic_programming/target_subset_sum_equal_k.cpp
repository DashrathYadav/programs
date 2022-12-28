#include<bits/stdc++.h>
using namespace std;

bool is_present(vector<int>arr,int n,int target)
{
   if(n<0)
   {
      return false;
   }
   if(target < 0)
   return false;

         if( target==0)
        return  true;

        if(target-arr[n]==0)
        return true;
      

        bool ans1=false;
        bool ans2=false;

       ans1= is_present(arr,n-1,target);

    
       ans2= is_present(arr,n-1,target-arr[n]);

        if(ans1|| ans2)
        return true;

        return false;


}

int main()
{

int n,k;
cin>>n>>k;

vector<int>arr(n);
for(int i=0;i<n;i++)
{
    cin>>arr[i];

}
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
    cout<<is_present(arr,n-1,k);

 return 0;
}