#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector < int > & histo) {
    stack < int > st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m) {
    int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }


    int maxArea = maximalAreaOfSubMatrixOfAll1(mat, n, m);
    cout << maxArea << "\n";
    return 0;
}
