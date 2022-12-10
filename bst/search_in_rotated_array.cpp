#include<bits/stdc++.h>
using namespace std;
int find_pivote(int a[],int n)
{
    if(a[0] <= a[n-1])
    return 0;

    else if(a[0]>a[n-1])
    {
       int start=0;
       int end =n-1;
       while(start <= end)
       {
           int mid=(start+end)/2;

           if(a[mid]<a[mid+1] && a[mid]< a[mid-1])
           return mid;

           else if (a[mid])
       }


    }

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    // 5 6 7 8 1 2 3 4
    //3 4 1
    //2 3 4 5 1
    int indx =find_pivote(a,n);

}