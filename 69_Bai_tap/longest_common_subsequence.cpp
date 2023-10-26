#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);


// int lcs(vector<int> x, vector<int> y, int n, int m)
// {
//     if (m == 0 || n == 0)
//         return 0;
//     if (x[n - 1] == y[m - 1])
//         return 1 + lcs(x, y, n - 1, m - 1);
//     else
//         return max(lcs(x, y, n, m - 1), lcs(x, y, n - 1, m));
// }

int lcs(vector<int> x, vector<int> y, int n, int m)
{
    int L[n + 1][m + 1];
    int i, j;

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[n][m];
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}


int main()
{
    int m,n, input;
    int count = 0;
    cin >> n >> m;

    vector<int> x, y;

    for(int i = 0; i < n; i++){
        cin >> input;
        x.push_back(input);
    }
    for(int i = 0; i < m; i++){
        cin >> input;
        y.push_back(input);
    }

    count = lcs(x,y,n,m);
    cout << count << endl;

}
