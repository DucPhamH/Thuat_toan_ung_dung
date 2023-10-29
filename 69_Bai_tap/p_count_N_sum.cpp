// Program to find the number of ways, n can be
// written as sum of two or more positive integers.
#include <bits/stdc++.h>
using namespace std;

// Returns number of ways to write n as sum of
// two or more positive integers
int countWays(int n)
{
	// table[i] will be storing the number of
	// solutions for value i. We need n+1 rows
	// as the table is constructed in bottom up
	// manner using the base case (n = 0)
	int table[n+1];

	// Initialize all table values as 0
	memset(table, 0, sizeof(table));

	// Base case (If given value is 0)
	table[0] = 1;

	// Pick all integer one by one and update the
	// table[] values after the index greater
	// than or equal to n
	for (int i=1; i<n; i++)
		for (int j=i; j<=n; j++)
			table[j] += table[j-i];

	return table[n] + 1;
}

// Driver program
int main()
{
	int n;
	cin >> n;
	cout << countWays(n);
	return 0;
}
