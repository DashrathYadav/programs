#include<bits/stdc++.h>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
/* Dynamic Programming C implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(string X, string Y, int m, int n)
{
	// intitalizing a matrix of size (m+1)*(n+1)
	int L[m + 1][n + 1];

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
		that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
	return L[m][n];
}


void solve(){

int n;
cin>>n;
string str;
cin>>str;
int maxi=0;
int mid=n/2;
int p=mid;
int q=mid+1;
for(int i=mid,j=mid-1;i<n-1 && j>=0;i++,j--)
{
    int l1=i+1;
    int l2=n-l1;

    if( maxi >=min(l1,l2) )
    continue;

  //  cout<<l1<<" "<<l2<<endl;
    
    string str1=str.substr(0,i+1);
    string str2=str.substr(i+1);

    int m=str1.size();
    int n=str2.size();
//cout<<m<<" "<<n<<endl;

    if( m<n )
    {
        reverse(str1.begin(),str1.end());
    }
    else{
        reverse(str2.begin(),str2.end());

    }
          maxi=max(maxi,lcs(str1,str2,m,n));

}
cout<<maxi<<endl;

//  cout<<lcs(X, Y, m, N)<<endl;
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