// tìm số có số lần xuất hiện nhiều nhất trong mảng. Nếu có nhiều số cùng xuất hiện nhiều nhất thì in ra số nhỏ nhất
// input 10
//       1 2 3 3 3 3 1 9 9 0
// output 3

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
    int dem = 0, res;
    for(int i = 0; i < n; i++){
        if(dem < cnt[a[i]]){
            dem = cnt[a[i]];
            res = a[i];
        }
        else if(dem == cnt[a[i]]){
            if(res > a[i]){
                res = a[i];
            }
        }
    }

// nếu đề yêu cầu in ra số dâu tiên xuất hiện nhiều nhất thì dùng cách này
    // int dem = 0, res;
    // for(int i = 0; i < n; i++){
    //    int cnt = 1;
    //      for(int j = i+1; j < n; j++){
    //           if(a[i] == a[j]){
    //             cnt++;
    //           }
    //      }
    //      if(dem < cnt){
    //         dem = cnt;
    //         res = a[i];
    //         }
    // }
    cout << res << endl;
}