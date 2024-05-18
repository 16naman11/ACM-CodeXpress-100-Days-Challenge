/*In the midst of the Cricket World Cup excitement, a unique ticketing system has been introduced. Each cricket match offers different ticket prices, and the challenge is to create packages of k distinct ticket types. The thrill of attending the match is determined by the smallest absolute difference in prices between any two selected ticket types. You are given an array of integer prices where price [i] denotes the price of the ith type of match ticket and an integer k, which represents the number of distinct ticket types in a package. The enjoyment value of a ticket package is the smallest absolute difference of the prices of any two tickets in the package. In the Cricket World Cup Ticket Pricing challenge, the goal is to find the maximum enjoyment value of a ticket package by selecting k distinct ticket types.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPairs(vector<int>& prices, int diff) {
    int count = 0;
    size_t left = 0; // Change to size_t
    for (size_t right = 0; right < prices.size(); ++right) { // Change to size_t
        while (prices[right] - prices[left] > diff) {
            left++;
        }
        count += right - left;
    }
    return count;
}

int maxEnjoymentValue(int N, int k, vector<int>& prices) {
    sort(prices.begin(), prices.end());
    int left = 0;
    int right = prices.back() - prices[0];

    while (left < right) {
        int mid = (left + right + 1) / 2;
        int count = 0;
        int prev = prices[0];

        for (int i = 1; i < N; ++i) {
            if (prices[i] - prev >= mid) {
                prev = prices[i];
                count++;
            }
        }

        if (count >= k - 1) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int N, k;
        cin >> N >> k;  // Size of the array and k
        vector<int> prices(N);

        for (int i = 0; i < N; ++i) {
            cin >> prices[i];  // Array of ticket prices
        }

        int result = maxEnjoymentValue(N, k, prices);
        cout << result << endl;
    }

    return 0;
}