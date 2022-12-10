#include<bits/stdc++.h>
using namespace std;

long long split_count_inversion(long long a[],long long start,long long mid,long long end)
{
   long long i=start;
   long long j=mid;
   long long k=0;
   long long cnt=0;
   long long temp[(end-start+1)];
    while((i< mid) && (j <=end))
    {
       if( a[i]<=a[j])
       {
        temp[k]=a[i];
        i++;
        k++;
       }
       else{
        temp[k]=a[j];
        cnt+=(mid-i);
        k++;
        j++;
       }
    }
    while(i < mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        temp[k]=a[j];
        j++;
        k++;
    }

    for(long long i=start,k=0;i<=end;i++,k++)
    {
        a[i]=temp[k];        
    }
    return cnt;
}


long long sort_count_inversion(long long a[],long long start,long long end)
{
    long long count=0;
    
    if(end > start)
    {

    long long mid=(start+end)/2;

    count+=sort_count_inversion(a,start,mid);

    count+=sort_count_inversion(a,mid+1,end);
    
    count+=split_count_inversion(a,start,mid+1,end);
    }
    return count;
}

int  main()
{
    long long n;
    cin>>n;
    long long a[n];
    long long count=0;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
     for(long long i=0;i<n;i++)
   {
    cout<<a[i]<<" ";
   } 
   
    cout<<sort_count_inversion(a,0,n-1)<<endl;
//    for(long long i=0;i<n;i++)
//    {
//     cout<<a[i]<<" ";
//    } 
}