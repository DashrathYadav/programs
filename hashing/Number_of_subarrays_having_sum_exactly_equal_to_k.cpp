// C++ program to find number of subarrays
// with sum exactly equal to k.
#include <bits/stdc++.h>
using namespace std;

// Function to find number of subarrays
// with sum exactly equal to k.
int findSubarraySum(int arr[], int n, int sum)
{
	// STL map to store number of subarrays
	// starting from index zero having
	// particular value of sum.
	unordered_map<int, int> prevSum;

	int res = 0;

	// Sum of elements so far.
	int currsum = 0;

	for (int i = 0; i < n; i++) {

		// Add current element to sum so far.
		currsum += arr[i];

		// If currsum is equal to desired sum,
		// then a new subarray is found. So
		// increase count of subarrays.
		if (currsum == sum)
			res++;

		// currsum exceeds given sum by currsum
		// - sum. Find number of subarrays having
		// this sum and exclude those subarrays
		// from currsum by increasing count by
		// same amount.
		if (prevSum.find(currsum - sum) != prevSum.end())
        {
            cout<<"reached"<<endl;
            cout<<currsum-sum<<endl;
            cout<<"current sum is"<<currsum<<endl;
            cout<<prevSum[currsum-sum]<<endl;
            cout<<i<<endl;
			res += (prevSum[currsum - sum]);
        }

		// Add currsum value to count of
		// different values of sum.
		prevSum[currsum]++;
	}

    unordered_map<int,int>:: iterator it;
    for(it=prevSum.begin();it!=prevSum.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

	return res;
}

int main()
{
	int arr[] = { 10, 2, -2, -20, 10 };
	int sum = -10;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findSubarraySum(arr, n, sum);
	return 0;
}
