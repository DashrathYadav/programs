#include<bits/stdc++.h>
using namespace std;


bool ispalindrom(int number)
{
    int temp=number,num=0;
    while(number !=0)
    {
        num=(num*10)+(number%10);
        number=number/10;
    }
    if(num==temp)
    return true;
    else return false;
}



void palindroms(int a[],int n,int k)
{ 
    int number=0;
    for(int i=0;i<k;i++)
    {
        number=number*10+a[i];
       // cout<<number<<endl;
    }
    if(ispalindrom(number)==true)
    {
        cout<<number<<endl;
    }

for(int i=k;i<n;i++)
{
    int poww=pow(10,k-1);
    number=((number)%poww)*10+a[i];
   // cout<<number<<endl;
    if(ispalindrom(number))
    {
        cout<<number<<endl;
    }
}



}

int main()
{
    int a[]={2,3,5,1,1,5};
    int k=4;
    int n= sizeof(a)/sizeof(a[0]);
  
    palindroms(a,n,k);
    return 0;

}