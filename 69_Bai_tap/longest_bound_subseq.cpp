//tim chuoi con co do dai lon nhat. co tong <=N
#include <iostream>
#include <vector>

using namespace std;

int findMaxSubsequence(const vector<int>& arr, int Q) {
    int n = arr.size();
    int left = 0, right = 0, currentSum = 0, maxLen = 0;

    while (right < n) {
        currentSum += arr[right];

        while (currentSum > Q) {
            currentSum -= arr[left];
            left++;
        }

        int currentLen = right - left + 1;
        if (currentLen > maxLen && currentSum <= Q) {
            maxLen = currentLen;
        }

        right++;
    }

    return (maxLen > 0) ? maxLen : -1;
}

int main() {
    int n, Q;
    cin >> n >> Q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findMaxSubsequence(arr, Q);

    cout << result << endl;

    return 0;
}
