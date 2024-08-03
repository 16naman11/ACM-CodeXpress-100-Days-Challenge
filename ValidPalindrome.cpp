/*Given a string s, print "yes" if the s can be palindrome after deleting at most one character from it and print "no" otherwise.

*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool canBePalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (canBePalindrome(s)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}