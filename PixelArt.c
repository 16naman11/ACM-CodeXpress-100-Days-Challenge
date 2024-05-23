/*Ram and Priya are digital artists participating in a Pixel Art Challenge, where they are creating mesmerizing artwork on a digital canvas. The canvas is represented as a 2D grid of pixels, where each pixel can either be illuminated (1) or in shadow (0). Each pixel interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules-

Any pixel with fewer than two illuminated(1) neighbors is shadowed(0)
Any pixel with two or three illuminated(1) neighbors remains illuminated(1)
Any pixel with more than three illuminated(1) neighbors gets shadowed(0)
Any shadowed(0) pixel with exactly three illuminated(1) neighbors becomes an illuminated(1) pixel
The next state is created by applying the above rules simultaneously to every pixel in the current state, where illumination and shadowing occur simultaneously. The challenge involves creating the artwork through iterations based on the rules. Your task is to output the next state after applying the above rules to the given mxn grid.*/

#include <stdio.h>

int countIlluminatedNeighbors(int matrix[25][25], int rows, int cols, int x, int y) {
    int count = 0;
    int directions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    
    for (int i = 0; i < 8; ++i) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        
        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && matrix[newX][newY] == 1) {
            count++;
        }
    }
    
    return count;
}

void nextState(int matrix[25][25], int rows, int cols) {
    int newMatrix[25][25];
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int count = countIlluminatedNeighbors(matrix, rows, cols, i, j);
            
            if (matrix[i][j] == 1) {
                if (count < 2 || count > 3) {
                    newMatrix[i][j] = 0;
                } else {
                    newMatrix[i][j] = 1;
                }
            } else {
                if (count == 3) {
                    newMatrix[i][j] = 1;
                } else {
                    newMatrix[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", newMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T, m, n;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &m, &n);
        int matrix[25][25];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        
        nextState(matrix, m, n);
    }

    return 0;
}