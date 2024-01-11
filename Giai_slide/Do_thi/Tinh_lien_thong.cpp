#include <bits/stdc++.h>
using namespace std;


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

void connected_component(){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            count++;
            cout << "Connected component " << count << ": ";
            DFS(i);
            cout << endl;
        }
    }
}



int main(){
    input();
    connected_component();
    return 0;
}



