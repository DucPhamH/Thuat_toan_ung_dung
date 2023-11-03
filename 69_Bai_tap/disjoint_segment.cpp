//C++
#include <bits/stdc++.h>
using namespace std;
#define N 1000000
pair<int,int> a[N];
int n;

bool check(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int solve(){
    int result = 0;
    int last = -1;
    sort(a+1, a + n + 1, check);
    for (int i = 1; i <= n; i++){
        if(a[i].first > last){
            result ++;
            last = a[i].second;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    cout << solve();



}
