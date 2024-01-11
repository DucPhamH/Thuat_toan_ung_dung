// cho day so nguyen N hay dem Q so cap 2 chi so khac nhau i , j trong dãy sao cho a[i] = a[j] va 1<=i<j<=N

// #include <bits/stdc++.h>
// using namespace std;
// const int MAXN = 1000005;
// int a[MAXN], n;
// int MOD = 1e9 + 7;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     long long ans = 0;
//     for(int i = 1; i <= n; i++){
//         for(int j = i + 1; j <= n; j++){
//             if(a[i] == a[j]){
//                 ans = (ans + 1) % MOD;
//             }
//         }
//     }
//     cout << ans;
// }
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], n;
int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    unordered_map<int, int> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t[a[i]]++;
    }

    long long ans = 0;
    for (auto &it : t) {
        long long count = it.second;
        cout << count << endl;
        ans = (ans + (count * (count - 1) / 2) % MOD) % MOD;
    }

    cout << ans;
    return 0;
}
