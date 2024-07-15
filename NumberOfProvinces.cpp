/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Print the total number of provinces.*/


#include <iostream>

#include <vector>

using namespace std;

int findProvince(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {

    if (visited[city]) {

        return 0;

    }

    visited[city] = true;

    for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {

        if (isConnected[city][neighbor] == 1) {

            findProvince(isConnected, visited, neighbor);

        }

    }

    return 1;

}

int countProvinces(vector<vector<int>>& isConnected) {

    int n = isConnected.size();

    vector<bool> visited(n, false);

    int provinces = 0;

    for (int city = 0; city < n; ++city) {

        provinces += findProvince(isConnected, visited, city);

    }

    return provinces;

}

int main() {

    int T;

    cin >> T;

    while (T--) {

        int n;

        cin >> n;

        vector<vector<int>> isConnected(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < n; ++j) {

                cin >> isConnected[i][j];

            }

        }

        int provinces = countProvinces(isConnected);

        cout << provinces << endl;

    }

    return 0;

}
