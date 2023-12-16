// input 5 5 10
//       9 4 10 3 7 
// output 5

#include <iostream>
using namespace std;
const int MAX = 100;
int a[MAX], n, A, B, res = 0;

void findSubsets(int nums[], int n)
{
   
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                sum += nums[j];
            }
        }
        if(sum >= A && sum <= B){
            res++;
        }
    }
    cout << res << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> A >> B;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    findSubsets(a, n);

}
