#include <bits/stdc++.h>
using namespace std;
#define N 10001
int nX, nY;
vector<int> T[N];
int match[N];
int rMatch[N];
int p[N];

int BFSFindPath(int u){
    for(int i=1;i<=nY;i++){
        p[i]=-1;
    }
    queue<int> Q;
    for(int x: T[u]){
        Q.push(x);
        p[x]=u;
    }
    //int cnt =0;
    while(!Q.empty()){
        //cnt++; if(cnt >10) break;
        int v=Q.front(); Q.pop();
        int mv = match[v];
        if(mv==-1)return v;
        for(int x: T[mv]){
            if(x != rMatch[mv]){
                Q.push(x);
                p[x]=mv;
            }
        }
    }
    return -1;
}

void increaseMatching(int s,int t){
    int x =t;
    int px = p[x];
    //int cnt=0;
    while(px!=s){
        //cnt++; if(cnt>10) break;
        int nx = rMatch[px];
        //match x and px
        match[px]=x;
        rMatch[px]=x;
        x=nx;
    }
    match[x]=px; rMatch[px]=x;
}

void maxMatching(){
    for(int j =1;j<=nX;j++){
        rMatch[j]=-1;
    }
    for(int i =1;i<=nY;i++){
        match[i]=-1;
    }
    set<int> NM;
    for(int j=1; j<=nX;j++){
        NM.insert(j);
    }
    int res=0;
    //int cnt=0;
    while(true){
        //cnt++; if(cnt >20) break;
        bool ok = false;
        for(int s:NM){
            int t = BFSFindPath(s);
            if(t!=-1){
                res+=1;
                increaseMatching(s,t);
                ok = true;
                NM.erase(s);
                break;
            }
        }
        if(!ok){
            break;
        }
    }
    cout << res;
}

void input(){
    cin >> nX >> nY;
    for(int j=1;j<=nX;j++){
        int k;
        cin >> k;
        for(int i=1;i<=k;i++){
            int v;
            cin >> v;
            T[j].push_back(v);
        }
    }
}
int main(){
    input();
    maxMatching();
    return 0;
}
