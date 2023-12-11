#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, a[MAXN], mem[MAXN];
int res = 0;

// void lengthDay() {
//     for (int i = 0; i < n; i++) {
//         int ans = 1; // Đặt lại ans cho mỗi dãy tăng mới
//         for (int j = i + 1; j < n; j++) {
//             if (a[j] > a[j - 1]) {
//                 ans++; // Tăng độ dài của dãy số tăng dần
//             } else {
//                 break; // Dừng nếu dãy số kết thúc
//             }
//         }
//         mem[i] = ans; // Lưu độ dài vào mảng mem
//     }
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
     int ans = 1;
    // lengthDay();
    for(int i = 1; i < n; i++){
       
        if(a[i] > a[i-1]){
            ans++;
        } else {
            ans = 1;
        }
        res = max(res, ans);
       
    }

    // for (int i = 0; i < n; i++) {
    //     res = max(res, mem[i]);
    // }
    cout << res << endl;

    return 0;
}



