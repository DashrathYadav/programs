#include<stdio.h>
int main()
{
int a[100],i,j,flag,n,temp,s;
scanf("%d",&n);
for(i=0;i<=n-1;i++)
{
  
scanf("%d",&a[i]);
}
for(s=0;s<n-1;s++)
{
  for(j=0;j<n-1-i;j++)
  {
    if(a[j]>a[j+1])
    {temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
    }
  }
  
    printf("\n%d",a[j+1]);
} 

  }



