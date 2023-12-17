// input 5
//       2 4 8 3 6
// output 48

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], n;

long long Max(long long a, long long b){
   if(a<b){
       return b;
   }
   return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max1 = -1e9-1, max2 = -1e9-1, min1 = 1e9+1, min2 = 1e9+1;
    for(int i = 0; i < n; i++){
        if(a[i] > max1){
            max2 = max1;
            max1 = a[i];
        } else if(a[i] > max2){
            max2 = a[i];
        }
        if(a[i] < min1){
            min2 = min1;
            min1 = a[i];
        } else if(a[i] < min2){
            min2 = a[i];
        }
    }
    //       2 4 8 3 6
    // i = 0 => max1 = 2, max2 = -1e9-1, min1 = 2, min2 = 1e9+1
    // i = 1 => max1 = 4, max2 = 2, min1 = 2, min2 = 4
    // i = 2 => max1 = 8, max2 = 4, min1 = 2, min2 = 4
    // i = 3 => max1 = 8, max2 = 4, min1 = 2, min2 = 3
    // i = 4 => max1 = 8, max2 = 6, min1 = 2, min2 = 3
    long long ans = Max(1ll*max1*max2, 1ll*min1*min2);
    cout << ans << endl;
    return 0;
}