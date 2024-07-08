/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Print the maximum of K values each time the sliding window moves right by one position.*/

#include <iostream>

#include <deque>

#include <vector>

using namespace std;

void printMaxKValues(const vector<int>& nums, int k) {

    deque<int> dq;

    // Process the first window

    for (int i = 0; i < k; ++i) {

        while (!dq.empty() && nums[i] >= nums[dq.back()]) {

            dq.pop_back();

        }

        dq.push_back(i);

    }

    // Process the rest of the windows

    for (int i = k; i < nums.size(); ++i) {

        cout << nums[dq.front()] << " ";

        // Remove elements outside the current window

        while (!dq.empty() && dq.front() <= i - k) {

            dq.pop_front();

        }

        // Remove smaller elements as they are not needed

        while (!dq.empty() && nums[i] >= nums[dq.back()]) {

            dq.pop_back();

        }

        dq.push_back(i);

    }

    cout << nums[dq.front()] << endl;  // Print the maximum of the last window

}

int main() {

    int T;

    cin >> T;

    for (int t = 0; t < T; ++t) {

        int n, k;

        cin >> n >> k;

        vector<int> nums(n);

        for (int i = 0; i < n; ++i) {

            cin >> nums[i];

        }

        printMaxKValues(nums, k);

    }

    return 0;

}