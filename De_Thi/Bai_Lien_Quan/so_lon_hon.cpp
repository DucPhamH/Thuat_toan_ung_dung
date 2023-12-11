// input 
// 6
// 1 2 9 2 0 22 
// output : 1 2 9 22


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int a[MAXN], n;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = a[0];
    
    for(int i = 0; i < n; i++){
       if(a[i] >= res){
           cout << a[i] << " ";
       }
       if(a[i] > res){
           res = a[i];
       }
    }
}
