#include<stdio.h>
int main()
{
  int max,t,a[1000],n,count;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    max=0;
    count=0;
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
      scanf("%d",&a[i]);
     }

     for(int i=0;i<n-1;i++)
     {
      for(int j=i+1;j<n;j++)
     {
      if(a[i]==a[j])
      {
        count++;
      }
    
     }
      if(count>max)
     {max=count;
     count=0;}
     else
     {
      count=0;
     }
     }
     int length=n-max-1;
     printf("%d\n",length);
  }
  

}