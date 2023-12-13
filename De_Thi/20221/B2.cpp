// input 10                                      output 10
//       8 5 7 9 10 4 7 2 2 6                           10
//       insert 3                                       9
//       delete-max                                     8
//       insert 6                                       8
//       insert 10
//       insert 7
//       insert 8
//       delete-max
//       delete-max
//       delete-max
//       delete-max
//       *


#include <bits/stdc++.h>
using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int> a, res;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      int p;
      cin >> p;
      a.push_back(p);
    }

    string temp,temp2, input;

    cin.ignore(0,'\n');
    while(1){
        getline(cin, input);
        if(input != "*"){
          istringstream split(input);
          split >> temp;
          // cout << temp << endl;
          if(temp == "delete-max"){
            sort(a.begin(), a.end());
            int t = a.back();
            res.push_back(t);
            a.pop_back();
          }else if(temp == "insert"){
            split >> temp2;
            // cout << temp2 << endl;
            int s = stoi(temp2);
            a.push_back(s);
          }
        }else break;
    }
   
    for(int i = 0; i < res.size(); i++){
      cout << res[i] << " ";
    }
    
}



