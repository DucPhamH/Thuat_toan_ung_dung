// input 
// 5
// 1 3 2 1 5


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n, a[MAXN], ans = 0;
int MOD = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
       int sum = 0;
       for(int j = i; j < n; j++){
          sum = sum + a[j];
          if(sum % 2 == 0){
              ans = (ans + 1) % MOD;
          }
       }
    }
    cout << ans << endl;
    return 0;
}

// 5
// 1 3 2 1 5

// i = 0 => j = 1 => sum = 1 + 3 = 4 => ans = 1  (1,3)
//          j = 2 => sum = 4 + 2 = 6 => ans = 2  (1,3,2)
//          j = 3 => sum = 6 + 1 = 7 => ans = 2  
//          j = 4 => sum = 7 + 5 = 12 => ans = 3 (1,3,2,1,5)
// i = 1 => j = 2 => sum = 3 + 2 = 5 => ans = 3  
//          j = 3 => sum = 5 + 1 = 6 => ans = 4 (3,2,1)
//          j = 4 => sum = 6 + 5 = 11 => ans = 4 
// i = 2 => j = 3 => sum = 2 + 1 = 3 => ans = 4
//          j = 4 => sum = 3 + 5 = 8 => ans = 5 (2,1,5)
// i = 3 => j = 4 => sum = 1 + 5 = 6 => ans = 6 (1,5)

// #include <bits/stdc++.h>
// using namespace std;
// const int MAXN = 1001;
// int n, a[MAXN], ans = 0;


// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < n; i++){
//        int sum = a[i];
//         cout << sum << endl;
//        for(int j = i+1; j < n; j++){
//           sum = sum + a[j];
//           if(sum % 2 == 0){
//               ans++;
//           }
//        }
//     }
//     cout << "kết quả:"<< ans << endl;
//     return 0;
// }