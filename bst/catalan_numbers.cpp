/*catalan sequence*/
#include<bits/stdc++.h>
using namespace std;

int c[100];


  int  catalen_no(int n)
{
    if(n==0)
    return 1;

    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=catalen_no(i)*catalen_no(n-1-i);
    }
    return ans;

    
    
}

int main()
{
    int n;
    cin>>n;
    c[0]=1;
    c[1]=1;
   int ans= catalen_no(n);

    
    
        cout<<ans<<" ";
    
    
}