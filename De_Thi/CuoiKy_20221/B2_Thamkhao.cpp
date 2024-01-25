//Tao sua code chat GPT thoi nhe

#include<bits/stdc++.h>
using namespace std;
#define N 100001

struct Edge
{
    int u,v,w;
};

Edge E[N];
int n,m;

void input(){
    scanf("%d%d",&n,&m);
    for(int k=0;k<m;k++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        E[k].u=u;
        E[k].v=v;
        E[k].w=w;
    }
}

//Disjoint Set
int p[N],r[N]; //p[v] là cha của v, r[v] là độ cao

int Find(int v){//find root
    if(v!=p[v]) p[v]=Find(p[v]);
    return p[v];
}

void Union(int x,int y){
    int rootX = Find(x);
    int rootY = Find(y);

    if(r[rootX] > r[rootY]){
        p[rootY] = rootX;
    } else {
        p[rootX] = rootY;
        if(r[rootX] == r[rootY]){
            r[rootY]++;
        }
    }
}

bool cmp(Edge& e1, Edge& e2){
    return e1.w < e2.w;
}

int Kruskal(){
    sort(E,E+m,cmp);
    for(int v = 1; v <= n; v++){
        p[v] = v; r[v] = 1;
    }
    
    int totalCost = 0;
    int edgesAdded = 0;

    for(int i = 0; i < m; i++){
        int u = E[i].u;
        int v = E[i].v;
        int w = E[i].w;

        int rootU = Find(u);
        int rootV = Find(v);

        if(rootU != rootV){ // Cạnh (u, v) có thể thêm vào cây
            totalCost += w;
            Union(rootU, rootV);
            edgesAdded++;

            if(edgesAdded == n - 1) break; // Đã thêm đủ n - 1 cạnh
        }
    }

    return totalCost;
}

int main(){
    input();

    int k;
    scanf("%d", &k);

    for(int i = 0; i < k; i++){
        int node;
        scanf("%d", &node);
    }

    int res = Kruskal();
    cout << res;
    return 0;
}
