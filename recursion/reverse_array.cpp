#include<bits/stdc++.h>
using namespace std;

void reverse(int a[],int n)
{
    if(n==0)
    return;

    reverse(a,n-1);
        int key=a[n];

    for(int i=n;i>=1;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=key;

    return;
}
int main()
{
    int a[6]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    reverse(a,n-1);
    cout<<endl;

 for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }


}