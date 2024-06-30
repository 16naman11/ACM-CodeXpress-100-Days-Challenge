/*You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Print the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.*/

#include <iostream>
#include <string>

using namespace std;

int minStringLengthAfterOperations(const string& s) {
    string result;
    bool removed = false;

    for (char ch : s) {
        if (!result.empty() && ((ch == 'B' && result.back() == 'A') || (ch == 'D' && result.back() == 'C'))) {
            result.pop_back();
            removed = true;
        } else {
            result.push_back(ch);
            removed = false;
        }
    }

    return result.length();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int result = minStringLengthAfterOperations(s);
        cout << result << endl;
    }

    return 0;
}