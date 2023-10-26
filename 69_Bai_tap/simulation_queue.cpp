#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    queue<string> S;
    string cmd, num;
    queue<string> popValue;

    // Đọc input cho đến khi gặp dấu "#"
    while (true) {
        cin >> cmd;
        if (cmd == "#") {
            break;
        }
        if (cmd == "PUSH") {
            cin >> num;
            S.push(num);
        } else if (cmd == "POP") {
            if(S.empty()){
                popValue.push("NULL");
            } else {
                string e = S.front(); //access the element on top of stack
                S.pop(); // pop (remove) the top element of stack
                popValue.push(e);
            }
        }
    }

    while (!popValue.empty())
    {
        string e = popValue.front();
        popValue.pop();
        cout << e << endl;
    }

    return 0;
}
