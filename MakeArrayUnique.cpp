/*You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Print the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minMovesToUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int moves = 0;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] <= nums[i - 1]) {
            moves += nums[i - 1] - nums[i] + 1;
            nums[i] = nums[i - 1] + 1;
        }
    }

    return moves;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        int result = minMovesToUnique(nums);
        cout << result << endl;
    }

    return 0;
}