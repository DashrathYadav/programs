#include<bits/stdc++.h>
using namespace std;
int main()
{

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
pq.push({1,{2,3}});
pq.push({2,{2,3}});
pq.push({1,{1,3}});
pq.push({1,{1,1}});
pq.push({1,{2,4}});

while(!pq.empty())
{
    auto node= pq.top();

    cout<<node.first<< " "<<node.second.first<<" "<<node.second.second<<" "<<endl;
pq.pop();

}
}