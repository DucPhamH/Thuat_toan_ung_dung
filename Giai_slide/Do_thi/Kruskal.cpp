#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v;
    int w;
};

const int maxn = 1001;
int n, m;
int parent[maxn], sz[maxn];
vector<edge> canh;


void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        edge e;
        e.u = x; e.v = y; e.w = w;
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    vector<edge> mst;
    int d = 0;
    //sort
    sort(canh.begin(), canh.end(), cmp);
    // Lap
    for(int i = 0; i < m; i++){
        if(mst.size() == n-1) break;
        edge e = canh[i];
        if(Union(e.u, e.v)){
            mst.push_back(e);
            d += e.w;
        }
    }
    if(mst.size() != n-1){
        cout << "Khong co cay khung";
    }else{
        cout << "MST: " << d << endl;
        for(int i = 0; i < mst.size(); i++){
            cout << mst[i].u << " " << mst[i].v << " " << mst[i].w << endl;
        }
    }
}
int main(){
    inp();
    make_set();
    kruskal();
    return 0;
}



