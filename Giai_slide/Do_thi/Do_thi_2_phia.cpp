#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1001;
vector<int> ke[maxn];
int color[maxn];

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    memset(color, -1, sizeof(color));
}

bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 0;
    while(!q.empty()){
       int v = q.front(); q.pop();
       for(int x : ke[v]){
           if(color[x] == -1){
               color[x] = 1 - color[v];
            //    q.push(x);
           } else if(color[x] == color[v]) return false;
       }
    }
    return true;
}

int main(){
    nhap();
    bool check = true;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!bfs(i)){
                check = false;
                break;
            }
        }
    }
    if(check) cout << "YES";
    else cout << "NO";
    return 0;
}



