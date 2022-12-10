#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={1,4,47,1,10,19};
    int x=51;
    int n=sizeof(a)/sizeof(a[0]);
    int sum=0;
    int fianal_size=INT_MAX;
    int current_size=INT_MAX;
    int i;
    int fianl_sum;
    int start=0;
    for( i=0;i<n;i++)
    {
        while(sum <= x && i<n)
        {
            sum=sum+a[i];
            i++;
        }  
        
        while(sum > x )
        {
            sum=sum-a[start];
            start++;
        }
        current_size=i-start+1;
        fianal_size=min(current_size,fianal_size);
        i--;


    }
    cout<<fianal_size<<endl;
   
}