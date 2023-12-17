// tìm và đếm tất cả các cặp số nguyen tố cùng nhau trong mảng
// input 5
//       2 4 8 3 6
// output 3

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int a[MAXN], n;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
  
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
           if(gcd(a[i], a[j]) == 1){
               ans++;
           }
        }
    }
    cout << ans << endl;

}