/*You and your friend are having a festive game night on Christmas Eve. You decide to play a game of Nim with some candy canes.

There are n candy canes on the table, and you go first.
On each turn, you can take 1, 2, or 3 candy canes from the table.
The one who takes the last candy cane wins the game and gets to eat it.
Determine the winner of the game, assuming both you and your friend play smartly. Print Yes if you can win, or No if you cannot.*/

#include <stdio.h>

// Function to determine the winner of the Nim game
char* nimWinner(int n) {
    return (n % 4 != 0) ? "Yes" : "No";
}

int main() {
    // Input the number of test cases
    int T;
    scanf("%d", &T);

    // Process each test case
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        char* result = nimWinner(n);
        printf("%s\n", result);
    }

    return 0;
}
