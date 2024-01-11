//tìm đường đi có chi phí thấp nhất trong ma trận biết rằng các ô có giái trị bằng 0 là các ô có quái vật, và người đi chỉ có thể di chuyển sang phải, xuống dưới và theo đường chéo sang phải xuống dưới
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<vector<int>> a(MAXN, vector<int>(MAXN));

// chú ý ko chạy code ko nổ máy tính
int minCostPath(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    if (a[0][0] == 0) return -1; 
    dp[0][0] = a[0][0];

 
    for (int i = 1; i < m; i++) {
        if (a[i][0] == 0) break;
        dp[i][0] = dp[i-1][0] + a[i][0];
    }
    for (int j = 1; j < n; j++) {
        if (a[0][j] == 0) break;
        dp[0][j] = dp[0][j-1] + a[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] == 0) continue;
            dp[i][j] = a[i][j] + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }

    return dp[m-1][n-1] > 0 ? dp[m-1][n-1] : -1; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> a[i][j];
        }
    }
    cout << minCostPath(a) << endl;


    

}