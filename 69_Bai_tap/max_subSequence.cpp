//C++
#include <bits/stdc++.h>
using namespace std;
int main() {
   int n, a, temp = 0, maxsum = 0;
   cin >> n;
   vector<int> my_vector;
   for(int i = 0; i < n; i++){
       cin >> a;
       my_vector.push_back(a);
   }
   for(int i=0;i<n;i++){
        temp+my_vector[i]<0 ? temp=0 : temp+=my_vector[i];
        if(temp > maxsum){
            maxsum = temp; //Gắn lại maxsum và vị trí kết thúc của dãy con
        }
    }

    cout << maxsum << endl;
}
