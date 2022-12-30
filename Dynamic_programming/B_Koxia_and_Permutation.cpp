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
 int k;
 cin>>n>>k;
  int i=1;
  int j=n;
  vector<int>ans;
  bool flag=1;
  while(i<j)
  {
        if(flag){
        ans.push_back(j);
        j--;
        flag=0;
        }
        else
        {
            ans.push_back(i);
            i++;
            flag=1;
        }
  }       
 ans.push_back(j);

        for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    nl;
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