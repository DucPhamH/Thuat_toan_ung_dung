//C++
#include <bits/stdc++.h>
using namespace std;


const int MAXN = 20;
int n;
int x[MAXN];

void print_sol(){
    for(int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void TRY(int k){
    for(int i = 0; i <= 1; i++){
        x[k] = i;
        if(k == n){
            print_sol();
        }else TRY(k+1);
    }
}

int main()
{
  cin >> n;
  TRY(1);
  return 0;
}
