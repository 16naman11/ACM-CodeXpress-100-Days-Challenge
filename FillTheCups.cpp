/*You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Print the minimum number of seconds needed to fill up all the cups.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        while (amount[0] + amount[1] + amount[2]) {
            sort(amount.begin(), amount.end());
            ++ans;
            amount[2]--;
            amount[1] = max(0, amount[1] - 1);
        }
        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<int> amount(3);

        for (int i = 0; i < 3; ++i) {
            cin >> amount[i];
        }

        Solution sol;
        int result = sol.fillCups(amount);

        cout << result << endl;
    }

    return 0;
}
