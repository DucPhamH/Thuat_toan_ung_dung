#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n, a[MAXN], pos, ans = 1;
int mem[MAXN];



int dp(int i){
    if(mem[i] != -1) return mem[i];
    int res = 1;
    for(int j = 1; j < i; j++){
        if(a[j] < a[i]){
            res = max(res, 1 + dp(j));
        }
    }
    return mem[i] = res;
}

int solve(){
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(ans < dp(i)){
            ans = dp(i);
            pos = i;
        }
    }
    return ans;
}

void trace(int i){
    for(int j = 1; j < i; j++){
        if(mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

void iter_trace(){
    int i = pos;
    for(int k = 0; k < ans; k++){
        cout << a[i] << " ";
        for(int j = 1; j < i; j++){
            if(a[j] < a[i] && mem[i] == 1 + mem[j]){
                i = j;
                break;
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(mem, -1, sizeof(mem));
    cin >> n;
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }
    ans = solve();
    cout << ans << endl;
    // trace(pos);
    iter_trace();

    return 0;
}
