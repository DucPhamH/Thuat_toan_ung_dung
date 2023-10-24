#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int N, X[MAXN], cot[MAXN], d1[MAXN], d2[MAXN];
int a[MAXN][MAXN];


void print_sol(){
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= N; i++){
        a[i][X[i]] = 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int i){
    // i - j + N là vị trí quân hậu sỏ hữu hàng chéo xuôi
    // i + j - 1 là vì trí quân hậu sử hữu hàng chéo ngược
   for(int j = 1; j <= N; j++){
       if(cot[j] == 1 && d1[i - j + N] == 1 && d2[i + j - 1] == 1){
           X[i] = j;
           cot[j] = d1[i - j + N] = d2[i + j - 1] = 0;
           if (i == N) print_sol();
           else Try(i+1);
           cot[j] = d1[i - j + N] = d2[i + j - 1] = 1;
       }
   }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i < MAXN; i++){
        cot[i] = d1[i] = d2[i] = 1;
    }
    Try(1);

    return 0;
}
