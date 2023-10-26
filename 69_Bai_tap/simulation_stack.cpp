//C++
#include <bits/stdc++.h>
using namespace std;

void PrintStack(stack<string> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
    string x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x << endl;

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

int main() {
    stack<string> S;
    string cmd, num;
    stack<string> popValue;

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
                string e = S.top(); //access the element on top of stack
                S.pop(); // pop (remove) the top element of stack
                popValue.push(e);
            }
        }
    }

    PrintStack(popValue);

    return 0;
}
