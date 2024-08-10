/*Given an n x n binary matrix grid, print the length of the shortest clear path in the matrix. If there is no clear path, print -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestClearPath(vector<vector<int>>& grid, int n) {
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int pathLength = 1;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            pair<int, int> curr = q.front();
            q.pop();

            for (const vector<int>& dir : directions) {
                int nx = curr.first + dir[0];
                int ny = curr.second + dir[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 0) {
                    if (nx == n - 1 && ny == n - 1)
                        return pathLength + 1;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        pathLength++;
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        int result = shortestClearPath(grid, n);
        cout << result << endl;
    }

    return 0;
}