//Đầu vào
//4
//1000 1600 101 200
//1901
//Đầu ra
//2
//Giải thích ví dụ: Kết quả bằng 2, vì có 2 tập hợp thỏa mãn tổng các phần tử ít nhất 1901 và chia hết cho 5 là {1000, 1600} và  {1000, 1600, 200}.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countWays(vector<int>& secretNumbers, int foundingYear) {
    int n = secretNumbers.size();
    int result = 0;

    // Sắp xếp danh sách số tự nhiên theo thứ tự tăng dần
    sort(secretNumbers.begin(), secretNumbers.end());

    // Duyệt qua tất cả các tập con của danh sách số tự nhiên
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<int> subset;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(secretNumbers[i]);
                sum += secretNumbers[i];
            }
        }

        // Kiểm tra điều kiện và cập nhật kết quả
        if (subset.size() > 0 && sum >= foundingYear && sum % 5 == 0) {
            ++result;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> secretNumbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> secretNumbers[i];
    }

    int foundingYear;
    cin >> foundingYear;

    int result = countWays(secretNumbers, foundingYear);
    cout << result << endl;

    return 0;
}
