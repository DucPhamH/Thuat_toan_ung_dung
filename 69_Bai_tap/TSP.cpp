#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int n, cur_cost = 0, opt_cost = INT_MAX;
int C[MAXN][MAXN], cmin = INT_MAX;
int x[MAXN], x_opt[MAXN];
bool visited[MAXN];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> C[i][j];
            if(i != j){
                cmin = min(cmin, C[i][j]);
            }
        }
    }
}

void Try(int k){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            x[k] = i;
            cur_cost += C[x[k-1]][i];
            visited[i] = true;
            if(k == n){
                if(cur_cost + C[i][1] < opt_cost){
                    opt_cost = cur_cost + C[i][1];
                    for(int j = 1; j <= n; j++){
                        x_opt[j] = x[j];
                    }
                }
            }else if (cur_cost + (n-k+1) * cmin < opt_cost){
                Try(k+1);
            }
            cur_cost -= C[x[k-1]][i];
            visited[i] = false;
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   input();
   x[1] = 1;
   visited[1] = true;
   Try(2);
   cout << opt_cost << endl;
//    for(int i = 1; i <= n; i++){
//        cout << x_opt[i] << " -> ";
//    }
//    cout << '1' << endl;
   return 0;
}
