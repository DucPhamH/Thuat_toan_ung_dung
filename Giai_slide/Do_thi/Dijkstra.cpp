#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 100001;
int n,m, s, t;
vector<pair<int, int>> adj[maxn];

void nhap(){
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

const int INF = 1e9;
int pre[maxn];

void dijkstra(int s, int t){
    vector<ll> d(n+1, INF);
    d[s] = 0;
    pre[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while(!Q.empty()){
       pair<int, int> top = Q.top(); Q.pop();
       int u = top.second;
       int kc = top.first;
       if(kc > d[u]) continue;
       for(auto it : adj[u]){
           int v = it.first;
           int w = it.second;
           if(d[v] > d[u] + w){
               d[v] = d[u] + w;
               Q.push({d[v], v});
               pre[v] = u;
           }
       }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << d[i] << " ";
    // }
    cout << d[t] << endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
    }
    reverse(path.begin(), path.end());
    for(int x : path){
        cout << x << " ";
    }

}
int main(){
    nhap();
    dijkstra(s, t);
    return 0;
}



