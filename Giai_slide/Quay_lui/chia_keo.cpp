#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n, m, x[MAXN];
int cur_candies = 0;



void print_sol(){
    for(int i = 1; i <= n; i++){
        cout << x[i] << ' ';
    }
    cout << endl;
}

void Try(int k){
    // x1, x2, ..., x[k-1]
    // x[k]: 1 ... m - cur_candies - (n-k)
    // if k == n; m - cur_candies - (n-k)
    int start_val = k == n ? m - cur_candies : 1;
    for(int i = start_val; i <= m - cur_candies - (n-k); i++){
        x[k] = i;
        cur_candies += i;
        if(k == n) print_sol();
        else Try(k+1);
        cur_candies -= i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    Try(1);

    return 0;
}
