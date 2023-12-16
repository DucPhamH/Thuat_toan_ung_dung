//Given 2 positive integers k and n. Write a program tat generates all k-combinations of 1, 2, ..., n in a lexicographic order.
// input 2 4
// output 1 2
//        1 3
//        1 4
//        2 3
//        2 4
//        3 4

// C++ program to print all combinations of size
// k of elements in set 1..n
#include <bits/stdc++.h>
using namespace std;

void makeCombiUtil(vector<vector<int> >& ans,
	vector<int>& tmp, int n, int left, int k)
{
	// Pushing this vector to a vector of vector
	if (k == 0) {
		ans.push_back(tmp);
		return;
	}

	// i iterates from left to n. First time
	// left will be 1
	for (int i = left; i <= n; ++i)
	{
		tmp.push_back(i);
		makeCombiUtil(ans, tmp, n, i + 1, k - 1);

		// Popping out last inserted element
		// from the vector
		tmp.pop_back();
	}
}

// Prints all combinations of size k of numbers
// from 1 to n.
vector<vector<int> > makeCombi(int n, int k)
{
	vector<vector<int> > ans;
	vector<int> tmp;
	makeCombiUtil(ans, tmp, n, 1, k);
	return ans;
}

// Driver code
int main()
{
	// given number
    int k, n;
	cin >> k >> n;
	vector<vector<int> > ans = makeCombi(n, k);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans.at(i).at(j) << " ";
		}
		cout << endl;
	}
	return 0;
}
