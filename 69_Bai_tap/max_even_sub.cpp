// tìm chuỗi con liên tiếp có tổng lớn nhất
// input 4
//       1 2 -3 4
// output 4

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int n, a[MAXN], res = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // for(int i = 0; i < n; i++){
    //     int sum = 0;
    //     for(int j = i; j < n; j++){
    //         sum = sum + a[j];
    //         res = max(res, sum);
    //     }
    // }
    // cout << res << endl;
    int maxEnd = a[0];
    int maxSoFar = a[0];

    for(int i = 1; i < n; i++){
        maxEnd = max(a[i], maxEnd + a[i]);
        maxSoFar = max(maxSoFar, maxEnd);
    }
    cout << maxSoFar << endl;
    return 0;
}

// #include <iostream>
// #include <climits>
// using namespace std;

// int maxSubArraySum(int a[], int size) {
//     int maxEndingHere = 0, maxSoFar = INT_MIN;

//     for (int i = 0; i < size; i++) {
//         maxEndingHere = maxEndingHere + a[i];
//         if (maxSoFar < maxEndingHere) {
//             maxSoFar = maxEndingHere;
//         }
//         if (maxEndingHere < 0) {
//             maxEndingHere = 0;
//         }
//     }
//     return maxSoFar;
// }

// int main() {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     int maxSum = maxSubArraySum(a, n);
//     cout << maxSum << endl;
//     return 0;
// }
