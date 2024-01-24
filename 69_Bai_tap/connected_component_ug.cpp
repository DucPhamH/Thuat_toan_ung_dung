//Cho do thi G=(V,E)
//V la so dinh
//E la so canh
//Canh khong co trong so, khong co huong
/* Example
Input
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8

Output
3 */

#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n, m; // n vertex, m edge
vector< vector<int> > vt;
bool visited[MAX];
int cnt = 0;

void input(){
    cin >> n >> m;
    vt.resize(n+1);

    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1].push_back(tmp2);
        vt[tmp2].push_back(tmp1);
    }
}

void explore(int x){
    visited[x] = true;
    for(int v : vt[x]){
        if(!visited[v]){
            explore(v);
        }
    }
}

void dfs(){
    for(int v=1; v<=n; v++){
        if(!visited[v]){
            cnt++;
            explore(v);
        }
    }
}

int main(){
    input();
    dfs();

    cout << cnt;
    return 0;
}
