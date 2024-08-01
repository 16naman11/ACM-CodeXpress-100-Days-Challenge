
/*Given an array of integers temperatures represents the daily temperatures, print an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev_index = st.top();
            st.pop();
            answer[prev_index] = i - prev_index;
        }
        st.push(i);
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> temperatures(n);
        for (int i = 0; i < n; ++i) {
            cin >> temperatures[i];
        }
        vector<int> result = dailyTemperatures(temperatures);
        for (int i = 0; i < n; ++i) {
            cout << result[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}