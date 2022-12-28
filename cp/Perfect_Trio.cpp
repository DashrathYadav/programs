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

 
 vector<int>v(3);
 
    cin>>v[0];
    cin>>v[1];
    cin>>v[2];
    sort(v.begin(),v.end());

    if(v[2] == v[0]+v[1])
    {cout<<"YES"<<endl;
    return;
    }

    cout<<"NO"<<endl;
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