#include<bits/stdc++.h>
using namespace std;

void reverse(int a[],int n);
int main()
{
    int a[6]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    reverse(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}S