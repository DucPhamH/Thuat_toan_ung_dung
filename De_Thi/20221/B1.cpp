// input 6 3 9
//       3 2 4 3 2 1
// output 3

// #include <bits/stdc++.h>
// using namespace std;
// const int MAXN = 1000005;
// int n, k, m;
// int a[MAXN], res = 0;



// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     cin >> n >> k >> m;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < n-k+1; i++){
//         int sum = 0;
//         for(int j = i; j < i+k; j++){
//             sum = sum + a[j];
//         }
//         if(sum == m){
//             res++;
//         }   
//     }
//     cout << res << endl;
// }


// kĩ thuật cửa sổ trượt
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, m;
    cin >> n >> k >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int sum = 0, res = 0;

    // Tính tổng của các phần tử đầu tiên trong cửa sổ k
    for (int i = 0; i < k; ++i) {
        sum += a[i];
    }

    // Kiểm tra cửa sổ đầu tiên
    if (sum == m) {
        res++;
    }

    // Di chuyển cửa sổ và tính tổng tiếp theo
    for (int i = k; i < n; ++i) {
        sum += a[i] - a[i - k]; // Thêm phần tử mới và bớt phần tử cũ
        if (sum == m) {
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
