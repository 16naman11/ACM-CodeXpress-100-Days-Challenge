/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and print the maximum profit you can achieve.*/


#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    return maxProfit;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }
        cout << maxProfit(prices) << endl;
    }

    return 0;
}