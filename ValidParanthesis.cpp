/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/


#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(const string& s) {
    stack<char> brackets;
    unordered_map<char, char> bracketMap = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            brackets.push(ch);
        } else {
            if (brackets.empty() || brackets.top() != bracketMap[ch]) {
                return false;
            }
            brackets.pop();
        }
    }

    return brackets.empty();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        if (isValid(s)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}