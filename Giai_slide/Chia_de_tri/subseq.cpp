#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int n;

int MaxLeftSeq(int i, int j){
    int sum = 0;
    int max_sum = a[j];
    for(int k = j; k >= i; k--){
        sum += a[k];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int MaxRightSeq(int i, int j){
    int sum = 0;
    int max_sum = a[i];
    for(int k = i; k <= j; k++){
        sum += a[k];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}


int maxSubSeq(int i, int j){
    if(i == j) return a[i];
    int mid = (i+j)/2;
    int wL = maxSubSeq(i, mid);
    int wR = maxSubSeq(mid+1, j);
    int wML = MaxLeftSeq(i, mid);
    int wMR = MaxRightSeq(mid+1, j);
    int wM = wML + wMR;
    return max(max(wL, wR), wM);

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << maxSubSeq(1, n);

    return 0;
}
