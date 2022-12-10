#include<bits/stdc++.h>
using namespace std;


bool time_given_satisfy(int a[],int n,int m,int time)
{
    int painter=1;
    int sum=0;

    for(int i=0;i<n;i++)
    {
        if(a[i] > time)
        return false;

        if(sum +a[i] > time)
        {
            painter++;
            if(painter > m)
            {
                return false;
            }
            sum=a[i];
        }

        else sum+=a[i];
    }
    return true;

}


int minimum_time(int a[],int n,int m)
{
   // sort(a[0],a[n-1]);
    
    if(n < m)
    return a[n-1];

    int start=a[n-1];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    int end=sum;
    int ans=0;
    while(start <= end)
    {
        int mid= (start+end)/2;

        if(time_given_satisfy(a,n,m,mid))
        {
            ans=mid;

            end=mid-1;
        }
        else {
            start=mid+1;
        }
        
    }
    return ans;


}

int main()
{
    int arr[]={10,20,60,50,30,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=3;
    cout<<minimum_time(arr,n,m);

}