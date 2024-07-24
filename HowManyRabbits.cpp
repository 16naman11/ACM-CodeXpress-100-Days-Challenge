/*There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, print the minimum number of rabbits that could be in the forest.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sum = a[0] + 1;

        for (int i = 1; i < n; i++) {
            int flag = 1;
            for (int j = 0; j < i; j++) {
                if (a[i] == a[j]) {
                    flag = 0;
                    break; 
                }
            }
            if (flag) {
                sum += a[i] + 1;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
