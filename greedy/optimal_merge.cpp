#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int ,vector<int>,greater<int> >arr;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push(a);
    }
    
    int ans=0;
    while(arr.size() > 1)
    {
        int f1= arr.top();
        arr.pop();
        int f2=arr.top();
        arr.pop();
       ans += f1 + f2;
       cout<<ans<<endl;
       
        arr.push(f1+f2);

    }
    cout<<ans<<endl;
}