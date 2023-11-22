#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
string X = "abcde";
string Y = "bdcabde";
int n, m;
int mem[MAXN][MAXN];

int dp(int i, int j){
    if(i == 0 || j == 0) return mem[i][j] = 0;
    if(mem[i][j] != -1) return mem[i][j];
    int res = -1;
    res = max(res, dp(i-1, j));
    res = max(res, dp(i, j-1));
    if(X[i-1] == Y[j-1]){
        res = max(res, 1 + dp(i-1, j-1));
    }
    return mem[i][j] = res;
}

void trace(int i, int j){
    if(i == 0 || j == 0) return;
    if(mem[i][j] == mem[i-1][j]){
        trace(i-1, j);
        return;
    }
    if(mem[i][j] == mem[i][j-1]){
        trace(i, j-1);
        return;
    }
    if(X[i-1] == Y[j-1] && mem[i][j] == 1 + mem[i-1][j-1]){
        trace(i-1, j-1);
        cout << X[i-1];
        return;
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(mem, -1, sizeof(mem));
    n = X.size();
    m = Y.size();
    cout << dp(n, m) << endl;
    trace(n, m);
    

    return 0;
}
