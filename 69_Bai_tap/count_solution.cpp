#include <bits/stdc++.h>
using namespace std;
#define MAX 20

int n, M;
int f ;
int c;
int a[MAX];
int t[MAX];
int x[MAX];

void initT(){
    t[1] = a[1];
    int i;
    for(i = 2; i<= n; i++){
        t[i] = t[i-1] + a[i];
    }
}

void solution(){
    if(f == M ){
        c++;
    }
}

void Try(int k){
    int v;
    for(v = 1; v <= (M - f - (t[n] - t[k]))/a[k]; v++){
        x[k] = v;
        f += a[k]*x[k];
        if(k == n){
            solution();
        }else {
            Try(k+1);
        }
        f -= a[k]*x[k];
    }
}

void input(){
    scanf("%d%d", &n, &M);
    int i;
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
}

void solve(){
    f = 0;
    initT();
    c = 0;
    Try(1);
    printf("%d", c);
}

int main(){
    input();
    solve();
    return 0;
}
