//C++
#include <bits/stdc++.h>
using namespace std;

// (a^b mod(m)) = [(a mod(m)) * (a mod(m)) ... (a mod(m))] mod(m) ( b lan)
int binpow(unsigned long long a, unsigned long long b, int m){
    unsigned long long res = 1;
    while(b > 0){
        if(b%2 == 1){
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }
    return res;
}

// int binpow2(unsigned long long a, unsigned long long b, int m){
//     unsigned long long res = 1;
//   for(int i=1; i<=b; i++){
//       res *= a;
//       res %= m;
//   }
//     return res;
// }

// Đặt x = a % m. Ta có ab ≡ xb (mod m)
// Bước này giảm a từ 1018 xuống x còn cỡ ~109
// Định lý Fermat nhỏ cho biết: ap ≡ a (mod p) với a bất kì và p là số nguyên tố,
// hay nói cách khác ap-1 ≡ 1 (mod p),
// hay aq(p-1) ≡ 1q ≡ 1 (mod p),
// hay aq(p-1) + r = aq(p-1)ar ≡ 1 * ar (mod p) = ar (mod p).
// Đặt r = b % (m - 1). Ta có xb ≡ xr (mod m) với m là số nguyên tố.
// Bước này giảm b từ 1018 xuống r còn cỡ ~109
// Để tính ab lẹ thì ta xài cách tính ab/2 * ab/2, ở đây có mod m vẫn xài được, vì ab mod m = a mod m * b mod m.

// Để tránh đệ quy thì ta phân tích b thành tổng của các số mũ 2.
// Ví dụ b = 12345 thì b = 1 + 8 + 16 + 32 + 4096 + 8192, vậy a12345 = a1 + 8 + 16 + 32 + 4096 + 8192 = a1a8a16a32a4096a8192.

// Để phân tích b ra thành tổng của các số mũ 2 thì ta chuyển b về nhị phân, từ đó ta biết được ở vị trí i nào (từ phải qua trái, bắt đầu từ 0) có số 1 thì tổng b có 1 số hạng 2i.
// Ví dụ ở đây b = (12345)10 = (11000000111001)2 có số 1 ở vị trí thứ 0, 3, 4, 5, 12, 13 từ phải qua thì tổng b = 20 + 23 + 24 + 25 + 212 + 213 = 1 + 8 + 16 + 32 + 4096 + 8192.

int binpow3(unsigned long long a, unsigned long long b, int m)
{
    unsigned long long res = 1;
    a %= m;
    b %= m - 1;
    while (b > 0) //vòng lặp phân tích b thành cơ số 2
    {
        if (b % 2 > 0)  //ở vị trí có số 1 thì nhân với a^(2^i) tương ứng. Tất cả các phép nhân đều có phép mod p theo sau.
            res = res * a % m;
        a = a * a % m;  //tính tiếp a^(2^(i+1)), a^1 -> a^2 -> a^4 -> a^8 -> a^16 v.v...
        b /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m = 1000000007;
    unsigned long long a, b;
    cin >> a >> b;
    cout << binpow3(a,b,m) << endl;

}
