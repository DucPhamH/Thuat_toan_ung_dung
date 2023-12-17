// tìm dãy con liên tiếp có 2 phân tử liền kề nhau trái dấu có độ dài dài nhất
// input 10
//       1 2 3 3 3 4 5 2 1 -3
// output 2

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = 0, cnt = 1;
    for(int i = 1; i < n; i++){
        if(a[i] * a[i-1] < 0){
            cnt++;
        } else {
            cnt = 1;
        }
        res = max(res, cnt);
    }
    if(res == 1){
        res = 0;
    }
    cout << res << endl;
}