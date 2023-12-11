// input 
// 5
// 1 2 2 3 5 ( không phải dãy tăng dần)
// output : No


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int a[MAXN], n;

int check(){
    for(int i = 1; i < n; i++){
        if(a[i] <= a[i-1]){
            return 0;
        }
    }
    return 1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(check()){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


}
