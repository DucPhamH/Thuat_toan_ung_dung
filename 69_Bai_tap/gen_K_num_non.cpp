#include <iostream>
#include <vector>
using namespace std;

void generatePartitions(int k, int n, vector<int> partition, int start = 1) {
    if (k == 0 && n == 0) {
        for (int i = 0; i < partition.size(); i++) {
            cout << partition[i];
            if (i < partition.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; i++) {
        partition.push_back(i);
        generatePartitions(k - 1, n - i, partition, i);
        partition.pop_back();
    }
}

int main() {
    int k, n;

    cin >> k;
    cin >> n;

    vector<int> partition;
    generatePartitions(k, n, partition);

    return 0;
}
