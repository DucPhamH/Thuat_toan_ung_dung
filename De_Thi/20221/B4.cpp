// input 5
//       2 5 4 6 7
// output 13
// Tập con tìm được là {2, 4, 7}


#include <iostream>
using namespace std;
const int MAX = 100005;
int a[MAX], n, res = 0;

int maxSumNoAdjacent(int arr[], int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return arr[0];

	int include = arr[0];
	int exclude = 0;

	for (int i = 1; i < n; i++) {
		int prevInclude = include;
		include = exclude + arr[i];
		exclude = max(prevInclude, exclude);
	}
    // i = 1 => include = 5, exclude = 2
    // i = 2 => include = 6, exclude = 5
    // i = 3 => include = 11, exclude = 6
    // i = 4 => include = 13, exclude = 11

	return max(include, exclude);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    } 

   int maxSum = maxSumNoAdjacent(a, n);
   cout<< maxSum << endl;
   return 0;

}


