#include <bits/stdc++.h>
using namespace std;

// input 10 11
// 1 2
// 1 3 
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
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

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int s = q.front(); q.pop();
        cout << s << " ";
        for(int i = 0; i < adj[s].size(); i++){
            int v = adj[s][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    input();
    BFS(1);
    return 0;
}



