#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n;
map<int, int> mem;
int imem[MAXN];


int fib(int n){
    if(n <= 2) return 1;
    if(imem[n] != -1) return imem[n];
    int res = fib(n-1) + fib(n-2);
    imem[n] = res;
    return res;
}

int fib_dp(int n){
    if(n <= 2) return 1;
    if(mem.find(n) != mem.end()){
        return mem[n];
    }
    int res = fib_dp(n-1) + fib_dp(n-2);
    return mem[n] = res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 1000; i++){
      imem[i] = -1;
    }
    cin >> n;
    
    
    cout << fib(n) << endl;
    for(int i = 1; i <= n; i++){
      cout << imem[i] << endl;
    }

    return 0;
}
