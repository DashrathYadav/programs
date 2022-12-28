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
umap mp;
int a;
 for(int i=0;i<n;i++ )
   {  cin>>a;
    mp[a]++;
   }


for(auto it : mp)
{
    if(it.second %2 ==1)
    {
        cout<<"NO"<<endl;
        return;
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