#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
vector<bool> visited(1001,false);

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i =1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }
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
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            BFS(i);
        }
    }
    return 0;
}
