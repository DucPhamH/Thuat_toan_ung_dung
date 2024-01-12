#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int n, m;
vector<pair<int, int>> adj[maxn];
bool used[maxn];

struct canh{
    int x,y,w;
};

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(used, false, sizeof(used));
}

void prim(int u){
    vector<canh> MST;
    int d = 0;
    used[u] = true;
    while (MST.size() < n-1){
        int min_w = INT_MAX;
        int X, Y;
        for(int i = 1; i<=n; i++){
            if(used[i]){
                for(pair<int, int> it : adj[i]){
                   int j = it.first, trongso = it.second;
                     if(!used[j] && min_w > trongso){
                          min_w = trongso;
                          X = i;
                          Y = j;
                     }
                }
               
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true;
    }
    cout << d << endl;
    for(canh it : MST){
        cout << it.x << " " << it.y << " " << it.w << endl;
    }
    
}

int main(){
    nhap();
    prim(1);
    return 0;
}



