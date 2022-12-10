#include<bits/stdc++.h>
using namespace std;
#define ll long long



void solve()
{
	ll n;
	cin>>n;
	string str;
	cin>>str;
	vector<pair<char,ll>>a;
ll maxi=1;
a.push_back({str[0],1});
ll cnt=0;
	for(ll i=1;i<n;i++)
	{
		if(str[i]==str[i-1])
		{
			a[cnt].second++;
		}
		else{

			a.push_back({str[i],1});
			cnt++;
		}
	}
	
	sort(a.begin(),a.end());

for(ll i=0;i<a.size();i++)
{
	if(a[i].second > maxi)
	{
		maxi=a[i].second;
	}
}
maxi=maxi-1;

for(ll i=1;i<a.size();i++)
{
		if(a[i-1].first == a[i].first)
		{
			ll m = min(a[i-1].second,a[i].second);
					if(m > maxi)
					maxi=m;
		}
}

cout<<maxi<<endl;


}

int  main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		
		solve();
	}
	
}