/*In an attempt to control the rise in population, Archer was asked to come up with a plan. This time he is targeting marriages. Archer, being as intelligent as he is, came up with the following plan:

A man with name M is allowed to marry a woman with name W, only if M is a subsequence of W or W is a subsequence of M.

A is said to be a subsequence of B, if A can be obtained by deleting some elements of B without changing the order of the remaining elements.

Your task is to determine whether a couple is allowed to marry or not, according to Archer's rule.*/

#include <iostream>

#include <string>

using namespace std;

bool isSubsequence(const string& M, const string& W) {

    int i = 0, j = 0;

    while (i < M.length() && j < W.length()) {

        if (M[i] == W[j]) {

            i++;

        }

        j++;

    }

    return i == M.length();

}

int main() {

    int T;

    cin >> T;

    while (T--) {

        string M, W;

        cin >> M >> W;

        if (isSubsequence(M, W) || isSubsequence(W, M)) {

            cout << "YES" << endl;

        } else {

            cout << "NO" << endl;

        }

    }

    return 0;

}