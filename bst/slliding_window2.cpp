#include<bits/stdc++.h>
using namespace std;

int addition(int x)
{
    int sum=0;
    while(x!=0)
    {
        sum=sum+(x%10);
        x=x/10;
    }
     
    return sum;
}
using namespace std;
int main()
{
   int a[]={84,23,45,14,56,82};

   int n=sizeof(a)/sizeof(a[0]);
   int k=3;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum=sum+addition(a[i]);
    }

  
    if(sum%3==0)
    {
        cout<<sum<<endl;
        return 0;
    }

    for(int i=k;i<n;i++)
    {
        sum=sum+addition(a[i])-addition(a[i-k]);

        if(sum%3==0)
    {
        int cnt=0;
        int j=i-k+1;
        while(cnt<k)
        {
            cout<<a[j]<<" ";
            cnt++;
            j++;
        }
        return 0;
    }
        
    }

 cout<<-1<<endl;
}