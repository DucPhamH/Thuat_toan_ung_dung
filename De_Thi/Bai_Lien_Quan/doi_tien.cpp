// ngân hàng có mệnh giá tiền là 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. số lượng tiền là không hạn chế. Một người có nhiệm vụ đổi một số tiền cho khách hàng. Hãy giúp người đó tìm ra số tờ tiền ít nhất cần phải đổi cho khách hàng.
// input 2 : là số bộ test
//       70 : là số tiền cần đổi
//       121 : là số tiền cần đổi
// output 2 : là số tờ tiền ít nhất cần đổi của 70
//        3 : là số tờ tiền ít nhất cần đổi của 121

#include <bits/stdc++.h>
using namespace std;
int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      int res = 0;
      for(int i = 9; i >= 0; i--){
        if(n >= a[i]){
          res += n/a[i];
          n = n%a[i];
        }
      }
      cout << res << endl;
    }
}