#include<bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n,string src,string help,string dest)
{
    if(n==0)
    return;
    TowerOfHanoi(n-1,src,dest,help);
    cout<<" "<<src<<" "<<" TO "<< dest<<endl;
    TowerOfHanoi(n-1,help,src,dest);
}

int main()
{
  int n;
  cin>>n;
  TowerOfHanoi(n,"A","B","C");

}