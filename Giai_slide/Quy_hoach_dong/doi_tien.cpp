#include <bits/stdc++.h>
using namespace std;
int INF = 100000;
int D[11], x, n;
int iMem[11][10001];

int minCoin(int i, int x){
    if(x < 0) return INF;
    if(x == 0) return 0;
    if(i == 0) return INF;
    if(iMem[i][x] != -1) return iMem[i][x];
    int res = INF;
    res = min(res, 1 + minCoin(i, x - D[i]));
    res = min(res, minCoin(i-1, x));
    iMem[i][x] = res;
    return res;

}

// void trace(int i, int x){
//     if(x == 0) return;
//     if(x < 0) return;
//     if(i == 0) return;

//     int res = INF;
//     if(iMem[i][x] == 1 + iMem[i][x - D[i]]){
//         cout << D[i] << " ";
//         trace(i, x - D[i]);
//     }
//     else trace(i-1, x);
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(iMem, -1, sizeof(iMem));
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> D[i];
    }
    minCoin(n, x);
    int ans = iMem[n][x];
    cout << ans << endl;
    for(int i = n; k = 0; k < ans; ++k){
        if(iMem[i][k] == 1 + iMem[i][x-D[i]]){
            cout << D[i] << " ";
            x -= D[i];
        }else {
            --i;
        }
    }
    return 0;
}