#include <bits/stdc++.h>
using namespace std;

// input 9 9 
// 1 2
// 1 3 
// 1 5 
// 2 4
// 3 6
// 3 7 
// 3 9
// 5 8 
// 8 9

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u){
    cout << u << " ";
  // danh dau u da duyet
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!visited[v]){
            DFS(v);
        }
    }
}

int main(){
    input();
    DFS(1);
    return 0;
}



