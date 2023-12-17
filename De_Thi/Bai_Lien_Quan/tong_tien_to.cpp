// cho mảng số nguyên , thực hiện tính toán tổng các phần tử trong đoạn từ vị trí L đến vị trí R của mảng
// input 
// dòng đầu tiên là số lượng phần tử của mảng n
// dòng thứ 2 là các phần tử của mảng
// dòng thứ 3 là số lượng truy vấn q
// q dòng tiếp theo là các truy vấn, mỗi truy vấn gồm 2 số nguyên L và R

// 10
// 1 2 3 4 5 6 7 8 9 10
// 3
// 1 3
// 1 10
// 2 5

// output 
// 6
// 55

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], n, q, l, r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
   long long prefix[MAXN];
   for(int i = 0; i < n; i++){
        if(i == 0){
            prefix[0] = a[0];
        } 
        prefix[i] = prefix[i-1] + a[i];
   }
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        --l; --r;
         if(l == 0){
              cout << prefix[r] << endl;
         } else {
              cout << prefix[r] - prefix[l-1] << endl;
         }
    }
}