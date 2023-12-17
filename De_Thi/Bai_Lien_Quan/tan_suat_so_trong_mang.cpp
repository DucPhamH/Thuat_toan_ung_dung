// cho mảng số nguyên, hãy liệt kê các giá trị xuất hiện trong mảng theo thứ tự xuất hiện, mỗi giá trị chỉ xuất hiện 1 lần
// input 10
//       1 2 3 3 3 3 1 9 9 0
// output 1 2 3 9 0

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
   for(int i = 0; i < n; i++){
       bool ok = true;
       for(int j = 0; j < i; j++){
           if(a[i] == a[j]){
               ok = false;
               break;
           }
       }
       if(ok){
           cout << a[i] << " ";
       }
   }
}