//input 4
//      1000 1601 100 200
//      1901
//output 5
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 21;
int a[MAXN], n, k, res = 0;


void findCountSubset(int a[], int n, int k){
   for(int i = 0; i < (1 << n); i++){
      set<int> temp;
      int sum = 0;
      for(int j = 0; j < n; j++){
         if((i & (1 << j)) != 0){
            if(temp.find(a[j]) != temp.end()){
               sum = 0;
               break;
            }
            temp.insert(a[j]);
            sum += a[j];
         }
      }
        if(sum >= k){
             res++;
        }
   }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    findCountSubset(a, n, k);   
}

