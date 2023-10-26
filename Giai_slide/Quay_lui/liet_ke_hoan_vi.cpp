#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n, x[MAXN];
bool marked[MAXN];

bool is_cand(int i, int k){
    if(k < 3) return true;
    if(x[k-2] > x[k-1]) return true;
    return x[k-1] > i;
}

void print_sol(){
    for(int i = 1; i <= n; i++){
        cout << x[i] << ' ';
    }
    cout << endl;
}

void Try(int k){
    for(int i = 1; i <= n; i++){
        if(!marked[i] && is_cand(i, k)){
            x[k] = i;
            marked[i] = true;
            if(k == n) print_sol();
            else Try(k+1);
            marked[i] = false;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Try(1);

    return 0;
}
