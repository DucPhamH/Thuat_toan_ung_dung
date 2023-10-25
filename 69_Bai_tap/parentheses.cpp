#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> temp;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if((str[i]=='{') || (str[i]=='(') || (str[i]=='[') || temp.empty()){
            temp.push(str[i]);
        }else if((temp.top() == '(' && str[i] == ')') || (temp.top() == '{' && str[i] == '}') || (temp.top() == '[' && str[i] == ']')){
            temp.pop();
        }else {
            temp.push(str[i]);
        }
    }
    if (temp.empty()) {

        // If stack is empty return true
        cout << '1';
    }else {
        cout << '0';
    }

}
