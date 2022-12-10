#include <bits/stdc++.h>

using namespace std;

bool is_allocation_true(int page[], int n, int m, int pages)
{
	int student = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (page[i] > pages)
			return false;

		if (sum + page[i] > pages)
		{
			student++;
			if (student > m)
				return false;

			sum = page[i];
		}
		else
			sum += page[i];
	}
	return true;
}

int find_min_pages(int page[], int n, int m)
{
	int minimum_page = 0;
	int allocating_page = 0;
	int maximum_page = 0;
	for (int i = 0; i < n; i++)
	{
		maximum_page += page[i];
	}

	while (minimum_page <= maximum_page)
	{
		allocating_page = (minimum_page + maximum_page) / 2;

		bool ans = is_allocation_true(page, n, m, allocating_page);

		if (ans == true)
			maximum_page = allocating_page - 1;

		else
		{
			minimum_page = allocating_page + 1;
		}
	}
	return allocating_page;
}

int main()
{
	int arr[] = {12, 34, 67, 90};
	int n = sizeof arr / sizeof arr[0];
	int m = 2; //No. of students

	int ans = find_min_pages(arr, n, m);
	cout << "maximum required mage is " << ans << endl;
}