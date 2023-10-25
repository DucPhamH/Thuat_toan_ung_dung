#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> map;
    string temp;
    int i = 0;
    queue<string> cmd;
    while(1){
        cin >> temp;
        if(temp != "*") map[temp] = i++;
        else break;
    }
    cin.ignore(1,'\n');
    while(1){
        getline(cin, temp);
        if(temp != "***")  cmd.push(temp);
        else break;

    }
    while(!cmd.empty()){
        temp = cmd.front();
        cmd.pop();
        istringstream split(temp);
        split >> temp;
        if(temp == "find"){
            split >> temp;
            if(map.count(temp) != 0) cout << "1";
            else cout << "0";
            if(!cmd.empty())cout << endl;
        }else{
            split >> temp;
            if(map.count(temp) == 0){
                map[temp] = i++;
                cout << "1";
            }
            else cout << "0";
            if(!cmd.empty()) cout << endl;
        }
    }
}
