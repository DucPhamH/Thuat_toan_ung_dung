#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const INF = 100000000;
int n;
int C[N][N], mem[N][1 << N];

int TSP(int i, int S){
    if(S == (1 << n) - 1) return mem[i][S] = C[i][0];
    if(mem[i][S] != -1) return mem[i][S];
    int res = INF;
    for(int j = 1; j <= n; j++){
        if((S & (1 << j)) == 0) continue;
        res = min(res, C[i][j] + TSP(j, S | (1 << j)));   
    }
    return mem[i][S] = res;

}

void trace(int i, int S){
    cout << i << " -> ";
    if(S == (1 << n) - 1) cout << 0 << endl;
    for(int j = 1; j <= n; j++){
        if(S & (1 << j)) continue;
        if(mem[i][S] == C[i][j] + mem[j][S | (1 << j)]){
            trace(j, S | (1 << j));
            break;
        }
    }
      
}

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
            cin >> C[i][j];
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(mem, -1, sizeof(mem));
    input();
    cout << TSP(0, 1) << endl;
    return 0;
}
