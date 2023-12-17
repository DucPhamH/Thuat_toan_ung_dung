// liệt kê các giá trị trong mảng và số lần xuất hiện của nó
// input 10
//       1 2 3 3 3 3 1 9 9 0

// output 1 2
//        2 1
//        3 4
//        9 2
//        0 1

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], n;
int cnt[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cnt[a[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(cnt[a[i]] != 0){
            cout << a[i] << " " << cnt[a[i]] << endl;
            cnt[a[i]] = 0;
        }
    }
    // nếu đề bài yêu cầu liệt kê các số chỉ xuất hiện 1 lần thì dùng cách này
    // for(int i = 0; i < n; i++){
    //     if(cnt[a[i]] == 1){
    //         cout << a[i] << " " << cnt[a[i]] << endl;
    //         cnt[a[i]] = 0;
    //     }
    // }
}