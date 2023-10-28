#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int n, M;



int countPair(int a[], int n, int M){
   sort(a, a + n);
   int x = 0, c = 0;
    for (int i = 0; i < n - 1; i++) {
        x = M - a[i];

        // Lower bound from i+1
        int y = lower_bound(a + i + 1, a + n, x) - a;

        // Upper bound from i+1
        int z = upper_bound(a + i + 1, a + n, x) - a;
        c = c + z - y;
    }
    return c;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> M;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

   cout << countPair(a, n ,M);


    return 0;
}
