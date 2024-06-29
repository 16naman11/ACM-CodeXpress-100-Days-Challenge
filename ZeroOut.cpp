/*You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Print the minimum number of operations to make every element in nums equal to 0.*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int operations = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            int x = nums[i];
            ++operations;
            for (int j = i; j < nums.size(); ++j) {
                nums[j] -= x;
            }
        }
    }

    return operations;
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

        int result = minOperations(nums);
        cout << result << endl;
    }

    return 0;
}