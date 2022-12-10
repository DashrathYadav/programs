

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    vector<vector<int>>a(k);
    for(int i=0;i<k;i++)
    {
        int size;
        cin>>size;
        a[i]=vector<int >(size);
        for(int j=0;j<size;j++)
        {
            cin>>a[i][j];
        }
    }

    priority_queue<pair<int ,int>,vector<pair<int ,int>>,greater<pair<int,int>>>pq;
    vector<int>idx(k,0);
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        pair<int,int >p;
        p.first=a[i][0];
        p.second=i;
        pq.push(p);
    }

    while(!pq.empty())
    {
        pair<int ,int> x=pq.top();
        pq.pop();
        ans.push_back(x.first);

        if(a[x.second].size() > idx[x.second]+1 )
        {
            pair<int ,int>p;
            idx[x.second]= idx[x.second]+1;
            int indx=idx[x.second];
            p.first=a[x.second][indx];
            p.second=x.second;
            pq.push(p);
             
        }

    }
    for(int i=0;i<ans.size();i++)
    {
    cout<<ans[i]<<" ";
    }
    return 0;
}