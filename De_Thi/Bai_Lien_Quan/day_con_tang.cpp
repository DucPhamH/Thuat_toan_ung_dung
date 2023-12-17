//tìm dãy con liên tiếp tăng dài nhất
// input 10
//       1 2 3 3 3 4 5 2 1 -3
// output 3 

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], n;

//in ra dãy con tăng dài nhất, nếu có nhiều dãy thì in ra dãy cuối cùng hoặc dãy đầu tiên
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = 0, cnt = 1, idx;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i-1]){
            cnt++;
        } else {
            cnt = 1;
        }
        if(res < cnt){
            res = cnt;
            idx = i-res+1;
        }
    }
    for(int i = 0; i < res; i++){
        cout << a[idx+i] << " ";
    }
    cout << res << endl;
}