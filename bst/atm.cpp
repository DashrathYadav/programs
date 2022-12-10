#include<stdio.h>
int main()
{
    int x ;
    float y;
   
    scanf("%d",&x);
    scanf("%f",&y);
  if((x%5!=0) || (x+0.5>y))
  {
printf("%.2f",y);
  }
  else{
      y=y-(x+0.50);
      printf("%.2f",y);
  }
 return 0;
}