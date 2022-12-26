/*
Count no of ways to reach nth stairs
 if from one stairs you can go up to 1 next or 2 next stairs or 3 next stairs
 */

#include<bits/stdc++.h>
using namespace std;


int main()
{
int n;
cin>>n;

 vector<int>stair(n+1);
 stair[0]=1;
 stair[1]=1;

    int ways_from_n_minus_1th_stair=0,ways_from_n_minus_2th_stair=0,ways_from_n_minus_3th_stair=0;
 for(int i=2;i<=n;i++)
 {
    if((i-1) >=0)
    ways_from_n_minus_1th_stair=stair[i-1];

    if( (i-2) >=0)
    ways_from_n_minus_2th_stair=stair[i-2];

    if( i-3 >=0)
    ways_from_n_minus_3th_stair=stair[i-3];

    stair[i]=ways_from_n_minus_1th_stair +  ways_from_n_minus_2th_stair  +   ways_from_n_minus_3th_stair;

    
 }

cout<<stair[n]<<endl;



 return 0;
}