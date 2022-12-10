#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int ,vector<int >>pq;
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        pq.push(a);
    }
    int sum=0;
    int cnt=0;
    while(!pq.empty())
    {
       int value=pq.top();
       pq.pop();
       sum=sum+value;
       cnt++;
       if(sum >=k)
       break;


    }
    if(sum < k)
    cout<<-1<<endl;
    else 
    cout<<cnt<<endl
    ;
}