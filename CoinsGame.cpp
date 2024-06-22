/*Dinesh is playing a game with his friend Mahesh. They have a pile containg N coins. Players take alternate turns, removing some coins from the pile. On each turn, a player can remove either one coin or coins equal to some prime power (i.e. p^x coins, where p - prime number and x - positive integer). Game ends when the pile becomes empty. The player who can not make a move in his turn loses.

Dinesh plays first. Your task is to find out who will win the game, provided that both of the player play optimally.*/

#include <stdio.h>

int main() {
    int t; // Number of test cases
    scanf("%d", &t);

    while (t--) {
        long int n; // Number of coins
        scanf("%ld", &n);

        (n%6!=0)?printf("Dinesh\n"):printf("Mahesh\n");
    }

    return 0;
}
