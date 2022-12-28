#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define nl cout<<"\n"
#define print cout<<

#define spc <<' ';
typedef priority_queue<int ,vector<int >,greater<int>> minheap;     //minheap pqmin   pqmin.push(x),top(),empty(),size()
typedef priority_queue<ll ,vector<ll >> maxheap;                  // maxheap pqmax
typedef unordered_map<int,int>umap;                               //  unordered map
typedef  map<int,int>omp;                                        //  ordered map  int x    map[x]++/map[x]=1   ...  (x is pushed in hash table with 0 freq;)
 //map<int ,int> :: iterator itm;
 //unordered_map<int ,int> :: iterator itum;
//vector<int >:: iterator itv;

void solve(){

 int n;
 cin>>n;
 vector<int>v(n);
 
 for(int i=0;i<n;i++)
 cin>>v[i];

maxheap pq;

for(int i=0;i<n;i++)
pq.push(v[i]);

// cout<<pq.size()<<endl;

while(!pq.empty())
{
    
    ll e1=pq.top();
    pq.pop(); 
    ll e2=pq.top();
    pq.pop();
     ll ans= e1*e2;
    pq.push(1);
    pq.push(ans);
    //cout<<e1<<" "<<e2<<endl;
    if(e1 ==1 || e2==1)
    break;

  

   
}
// cout<<pq.size()<<endl;
ll sum=0;
while(!pq.empty())
{
    if(pq.top()==1)
    break;
    sum+=pq.top();
    pq.pop();
}
sum+=pq.size();
// cout<<sum<<endl;
cout<< (2022*sum)<<endl;
return;

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int tc;
    cin>>tc;
     
    for(int i=1;i<=tc;i++)
    {
        solve();

    }
 return 0;
}