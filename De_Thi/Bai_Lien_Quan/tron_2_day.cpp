// trộn 2 mảng đã sắp xếp tăng dần thành 1 mảng đã sắp xếp tăng dần
// input 4 5
//       1 2 2 3
//       1 2 3 5 9
// output 1 1 2 2 2 3 3 5 9
//    qsort(arr,num,sizeof(int),compare);
//    sort(a, a+n);

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], b[MAXN], c[MAXN], n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int i = 0, j = 0, k = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            c[k++] = a[i];
            ++i; 
        } else {
            c[k++] = b[j];
            ++j;
        }
    }
    while(i < n){
        c[k++] = a[i++];
    }
    while(j < m){
        c[k++] = b[j++];
    }
    for(int i = 0; i < n+m; i++){
        cout << c[i] << " ";
    }
    cout << endl;
}