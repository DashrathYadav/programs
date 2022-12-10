//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// 1
// 12
// 20 7 9 6 9 21 12 3 12 16 1 27
// } Driver Code Ends
class Solution
{
public:
	int cnt = 0;
	int flag = 0;
	int left = 0;
	int right = 0;
	int count(vector<int> a, int indx, vector<int> ans, vector<vector<int>> &dp)
	{
	int left = 0;
		if (indx == 0)
		{

			return ans.size() - 1;
		}
	if(dp[0][indx] !=-1)
				return dp[0][indx];

		if (ans.size() == 0)
			ans.push_back(a[indx]);

		for (int i = indx - 1; i >= 0; i--)
		{

			if (ans.back() > a[i])
			{		
				

				ans.push_back(a[i]);
				int l1=count(a, i, ans, dp);
				left = ans.size() - 1;

				ans.pop_back();
				int l2 = count(a, i, ans, dp);
				int sz = ans.size() - 1;
				left =max(l1, max(l2,max(left, sz)));
				
				
			}
		}

		ans.pop_back();
		if (left > cnt)
			cnt = left;

		return left;
	}

	int countr(vector<int> a, int indx, vector<int> ans, vector<vector<int>> &dp)
	{
		int right = 0;
		if (indx == a.size() - 1)
		{

			return ans.size() - 1;
		}
				if(dp[1][indx] !=-1)
				return dp[1][indx];
				
		if (ans.size() == 0)
				ans.push_back(a[indx]);

		for (int j = indx + 1; j < a.size(); j++)
		{

			
		
			if ((ans.back() > a[j]))
			{
				ans.push_back(a[j]);

				int r1 = countr(a, j, ans, dp);
				right = ans.size() - 1;
				

				ans.pop_back();
				int r2=countr(a, j, ans, dp);
				int sz = ans.size() - 1;
				right =max(max(r1,r2), max(right, sz));
			}
		}
		ans.pop_back();
		if (right > cnt)
			cnt = right;

		return right;
	}

	int LongestBitonicSequence(vector<int> nums)
	{

		vector<int> ans;
		vector<vector<int>> dp(3, vector<int>(nums.size() + 1, -1));
		int maxi = 0;

		// cout<<count(nums,3,ans,dp);
		// cout<<endl;
		
		for (int i = 0; i < nums.size(); i++)
		{
			int l = 0;
			int r = 0;
			cnt = 0;
			count(nums, i, ans, dp);
			l = cnt;
			dp[0][i] = l;

		}
		
	for (int i = nums.size(); i >=0; i--)
		{
			int l = 0;
			int r = 0;
			cnt = 0;
			
			countr(nums,i, ans, dp);
			r = cnt;

			dp[1][i] = r;
		
		}


		for (int j = 0; j < nums.size(); j++)
		{
			cout << dp[0][j] << " " << dp[1][j] << endl;
			maxi=max(maxi,dp[0][j]+dp[1][j]+1);
		}

		return maxi;
	}
};

//{ Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends