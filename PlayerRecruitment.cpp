/*You have an array called 'indian_team' that contains the jersey numbers of players currently in the squad. The goal is to intelligently pick k distinct players (represented as positive integers) who are not presently in the team. Each player's cost is determined by the number on their jersey. Your objective is to choose k new distinct players, not in the current team, in a way that minimizes the total cost acquired by adding them to the team. Provide the minimum cost required to add k new players.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long findMinimumCost(int n, int k, vector<int>& indian_team) {

    sort(indian_team.begin(), indian_team.end());

    long long cost = 0;

    int current = 1;

    for (int i = 0; i < n && k > 0; ++i) {

        if (indian_team[i] == current) {

            ++current;

        } else {

            cost += current;

            ++current;

            --k;

            --i;

        }

    }

    while (k > 0) {

        cost += current;

        ++current;

        --k;

    }

    return cost;

}

int main() {

    int T;

    cin >> T;

    for (int t = 0; t < T; ++t) {

        int n, k;

        cin >> n >> k;

        vector<int> indian_team(n);

        for (int i = 0; i < n; ++i) {

            cin >> indian_team[i];

        }

        long long result = findMinimumCost(n, k, indian_team);

        cout << result << endl;

    }

    return 0;

}