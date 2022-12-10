
#include <stdio.h>
#include <math.h>
int main() {
int i,arr[1000],n,t,k,l,z,sum;

scanf("%d",&t);
for(k=0;k<t;k++)  
{
    sum=0;
    scanf("%d",&n);
    
for(i=0;i<n;i++)    
   {
       scanf("%d",&arr[i]);
   }
   if(n%2==0){
 for(l=0;l<n;l++)
 {
     sum=sum+arr[l];
 }
 
 z=sum/2;
 z=abs(z);
 printf("%d\n",z);
 }
 else{
     printf("-1\n");
 }
}
}