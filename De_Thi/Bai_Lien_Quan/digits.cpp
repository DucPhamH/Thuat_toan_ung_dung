#include<bits/stdc++.h>
using namespace std;
const int MAX = 20;
int n;
int x[MAX]; // x[0] = I, x[1] = C, x[2] = T, x[3] = K, x[4] = H, x[5] = U, x[6] = S
bool visited[MAX];
int cnt;

void input(){
    cin >> n;
    for(int i=0; i<MAX; i++)
        visited[i] = false;
    cnt = 0;
}

bool check(int a, int i){
    if(a == 0 && i == 0) return false;
    if(a == 2 && i == 0) return false;
    if(visited[i]) return false;

    return true;
}

void solution(){
  int ICT = x[0]*100 + x[1]*10 + x[2];
  int K62 = x[3]*100 + 6*10 + 2;
  int HUST = x[4]*1000 + x[5]*100 + x[6]*10 + x[2];

  if(ICT - K62 + HUST == n) cnt++;  
}

void TRY(int a){
    for(int i=1; i<10; i++){
        if(check(a,i)){
            visited[i] = true;
            x[a] = i;

            if(a == 6) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;

    while(T>0){
        input();
        TRY(0);
        cout << cnt << endl;
        T--;
    }
    return 0;
}