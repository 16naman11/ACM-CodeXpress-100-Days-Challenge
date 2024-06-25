/*You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x. At the end of the game, there is at most one stone left.

Print the weight of the last remaining stone. If there are no stones left, Print 0*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lastRemainingStone(vector<int>& stones) {
    while (stones.size() > 1) {
        sort(stones.begin(), stones.end(), greater<int>());
        int x = stones[0];
        int y = stones[1];
        stones.erase(stones.begin(), stones.begin() + 2);
        if (x != y) {
            stones.push_back(abs(y - x)); // Use abs to avoid negative values
        }
    }
    return (stones.empty()) ? 0 : stones[0];
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        vector<int> stones(n);
        for (int i = 0; i < n; ++i) {
            cin >> stones[i];
        }

        int result = lastRemainingStone(stones);
        cout << result << endl;
    }

    return 0;
}