#include<bits/stdc++.h>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
/* Dynamic Programming C implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

char* substring(char *destination, const char *source, int beg, int n)
{
    // extracts `n` characters from the source string starting from `beg` index
    // and copy them into the destination string
    while (n > 0)
    {
        *destination = *(source + beg);
 
        destination++;
        source++;
        n--;
    }
 
    // null terminate destination string
    *destination = '\0';
 
    // return the destination string
    return destination;
}


/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char * X, char* Y, int m, int n)
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
char str[n];
char *s=str;
scanf("%s",str);
// string str;
// cin>>str;
int maxi=0;
int mid=n/2;
int p=mid;
int q=mid+1;
for(int i=0;i<n;i++)
{
    int l1=i+1;
    int l2=n-l1;

    if( maxi >=min(l1,l2) )
    continue;

   cout<<l1<<" "<<l2<<endl;
    char str1[l1];
    char str2[l2];
    *str1=substring(str1,str,0,l1);
     substring(str2,str,i+1,l2);
printf("%s\n",str1);
printf("%s\n",str2);
//cout<<m<<" "<<n<<endl;

    if( l1<l2 )
    {
        strrev(str1);
    }
    else{
        strrev(str2);
    }
          maxi=max(maxi,lcs(str1,str2,l1,l2));

}
cout<<maxi<<"\n";

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