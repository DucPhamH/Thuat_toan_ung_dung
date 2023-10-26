#include <bits/stdc++.h>
using namespace std;
// long double gt(int n) {
// 	long double s = 1;

// 	for (int i = 1; i <= n; i++){
// 		s *= i;
//     }
// 	return s;
// }
const int Modulo = 1000000007;
int factorials[100001];
void calculateFactorials() {

        long f = 1;

        for (int i = 1; i < 100001; i++) {
            f = (f * i) % Modulo;
            factorials[i] = (int) f;
        }
}

long long modInverse(long long A, long long M)
{
    long long m0 = M;
    long long y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {

        long long q = A / M;
        long long t = M;

        M = A % M;
        A = t;
        t = y;


        y = x - q * y;
        x = t;
    }


    if (x < 0)
        x += m0;

    return x;
}
long long C(int k, int n) {
    calculateFactorials();

    long long a = modInverse(factorials[k], Modulo);
    long long b = modInverse(factorials[n - k], Modulo);
        return factorials[n] * a % Modulo * b % Modulo;
}
int main(){
	int n, k;
	// cout << "Nhap k: ";
	// cin >> k;
	// cout << "Nhap n: ";
	// cin >> n;
    cin >> k >> n;
	cout << C(k, n);
	// system("pause");
	return 0;
}
