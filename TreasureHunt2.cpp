/*You are an adventurer who enters a dungeon full of gold and monsters. The dungeon is a m x n grid, where each cell contains a number of gold coins or a monster (represented by 0). You want to collect as much gold as possible before leaving the dungeon.

How can you do that, given the following rules:

You start from any cell that has gold coins, and you can end at any cell that has gold coins.
You can move one step up, down, left, or right from your current cell, as long as you don’t go outside the grid or enter a cell that you have already visited.
You can’t enter a cell that has a monster.
You collect all the gold coins in the cell that you enter.*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxGold(vector<vector<int>>& grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();
    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0) {
        return 0;
    }

    int currentGold = grid[row][col];
    grid[row][col] = 0; 

    int up = getMaxGold(grid, row - 1, col);
    int down = getMaxGold(grid, row + 1, col);
    int left = getMaxGold(grid, row, col - 1);
    int right = getMaxGold(grid, row, col + 1);

    grid[row][col] = currentGold;

    return currentGold + max({up, down, left, right});
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        int maxGold = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, getMaxGold(grid, i, j));
                }
            }
        }

        cout << maxGold << endl;
    }

    return 0;
}