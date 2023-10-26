#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000005; // khai báo size của mảng
const int LOG = 17; // khai báo size hàm log
int a[MAX_N];
int m[MAX_N][LOG];
int total = 0;


int query(int L, int R) { // O(1)
    // l là giá trị đầu, R là giá trị cuối
	int length = R - L + 1;

	// chuyển k sang hàm giá trị của hàm log
	int k = 0;
	while((1 << (k+1)) <= length){
	    k++;
	}
	return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {

	//Nhập n
	int n;
	cin >> n;

   //gán hàng đầu tiên
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
	}

	//công thức bảng thưa thớt
	for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
		}
	}

	//Nhập số chuỗi con cần input vào
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		total += query(L, R);
	}
	cout << total << endl;
}
