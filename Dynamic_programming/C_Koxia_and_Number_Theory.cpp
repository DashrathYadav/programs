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
typedef priority_queue<int ,vector<int >> maxheap;                  // maxheap pqmax
typedef unordered_map<int,int>umap;                               //  unordered map
typedef  map<int,int>omp;                                        //  ordered map  int x    map[x]++/map[x]=1   ...  (x is pushed in hash table with 0 freq;)
 //map<int ,int> :: iterator itm;
 //unordered_map<int ,int> :: iterator itum;
//vector<int >:: iterator itv;

void solve(){

 int n;
 cin>>n;

set<ll>s;
ll a;
 for(int i=0;i<n;i++)
{
    cin>>a;
    s.insert(a);
}   

if(s.size() < n)
{
    cout<<"NO"<<endl;
    return;
}

int odd_cnt=0;
int eve_cnt=0;

 for(auto it : s)
 {
     if( it & 1)
     odd_cnt++;
     else
     eve_cnt++;
 }  

if(eve_cnt>=2 && odd_cnt >=2)
{
    cout<<"NO"<<endl;
    return;
}

 for(auto it : s)
 {
     for( auto i : s){
  
     if( i==it)
     continue;

    if( __gcd(i,it)==1)
    {
        cout<<"NO"<<endl;
        return;
    }
     }

 }  



cout<<"YES"<<endl;
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