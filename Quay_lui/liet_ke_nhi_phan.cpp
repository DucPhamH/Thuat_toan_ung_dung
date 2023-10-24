#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n;
int A[MAXN];

void print_sol(){
    for(int i = 1; i <= n; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}

void Try(int k){
    for(int i = 0; i <= 1; i++){
        A[k] = i;
        if(k == n) print_sol();
        else Try(k+1);
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
