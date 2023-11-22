#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n, a[MAXN];
bool bMark[MAXN];
int iMem[MAXN];

int MaxSum(int i){
    if(i == 1) return a[i];
    if(bMark[i]) return iMem[i];
    int res = max(a[i], a[i] + MaxSum(i-1));
    iMem[i] = res;
    bMark[i] = true;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(bMark, 0, sizeof(bMark));
    cin >> n;
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }
    
    MaxSum(n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, iMem[i]);
    }
    
    cout << ans;
    
    

    return 0;
}
