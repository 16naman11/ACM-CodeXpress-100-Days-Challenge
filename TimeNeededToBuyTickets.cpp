/*There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Print the time taken for the person at position k (0-indexed) to finish buying tickets.*/

#include <iostream>
#include <vector>

using namespace std;

int calculateTime(int n, int k, vector<int>& tickets) {
    vector<int> queue(tickets.begin(), tickets.end());
    int time = 0;

    while (queue[k] > 0) {
        for (int i = 0; i < n; i++) {
            if (queue[i] > 0) {
                queue[i]--;
                time++;
                if (i == k && queue[i] == 0) {
                    return time;
                }
            }
        }
    }

    return time;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> tickets(n);
        for (int i = 0; i < n; i++) {
            cin >> tickets[i];
        }

        int time = calculateTime(n, k, tickets);
        cout << time << endl;
    }

    return 0;
}