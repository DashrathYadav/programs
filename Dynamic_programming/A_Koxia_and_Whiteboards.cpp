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
typedef priority_queue<ll ,vector<ll >,greater<ll>> minheap;     //minheap pqmin   pqmin.push(x),top(),empty(),size()
typedef priority_queue<int ,vector<int >> maxheap;                  // maxheap pqmax
typedef unordered_map<int,int>umap;                               //  unordered map
typedef  map<int,int>omp;                                        //  ordered map  int x    map[x]++/map[x]=1   ...  (x is pushed in hash table with 0 freq;)
 //map<int ,int> :: iterator itm;
 //unordered_map<int ,int> :: iterator itum;
//vector<int >:: iterator itv;

void solve(){

 int n,m;
 cin>>n>>m;

 vector<int>a(n);
 vector<int>b(m);

 for(int i=0;i<n;i++)
 {
    cin>>a[i];
 }       

 for(int i=0;i<m;i++)
 {
    cin>>b[i];
 }       

 minheap hp;

 for(int i=0;i<n;i++)
 {
    hp.push(a[i]);
 }
 for(int j=0;j<m;j++)
 {
    hp.pop();
    hp.push(b[j]);
    
 }

 ll sum=0;
 while(!hp.empty())
 {
    sum+=hp.top();
    hp.pop();
 }

cout<<sum<<endl;
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