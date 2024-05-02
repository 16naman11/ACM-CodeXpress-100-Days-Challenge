/*Mohan and Rohan are celebrating Diwali by playing an exciting game with their friends. They each have their own set of cards, Mohan's cards represented by the array M and Rohan's cards by the array R. These cards have either numbers or symbols on them. The numbers denote the amount of sweets they can enjoy, while the symbols indicate specific actions they must perform.

The available symbols are: ‘D’: Double the current score ‘H’: Half the current score

The game rules are:

Both players start with a score of zero.
They take turns selecting a card from their respective arrays and add its value to their current score based on the card's nature:
If the card is a number, they simply add that number to their current score.
If the card is 'D', they double their current score.
If the card is 'H', they halve their current score.
They continue to play in turns until they have no more cards left in their array and the player with the highest score is declared winner.*/

#include <stdio.h>

int main() {
    int T, N, i, j, k, mtotal = 0, rtotal = 0;
    char M[5000], R[5000];
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d", &N);

        
        for (j = 0; j < N; j++) {
            scanf(" %c", &M[j]); 
            if (M[j] >= '0' && M[j] <= '9') {
                mtotal += M[j] - '0';
            } else if (M[j] == 'D') {
                mtotal *= 2;
            } else if (M[j] == 'H') {
                mtotal /= 2;
            }
        }

        
        for (k = 0; k < N; k++) {
            scanf(" %c", &R[k]); 
            if (R[k] >= '0' && R[k] <= '9') {
                rtotal += R[k] - '0';
            } else if (R[k] == 'D') {
                rtotal *= 2;
            } else if (R[k] == 'H') {
                rtotal /= 2;
            }
        }

        if (rtotal < mtotal) {
            printf("Mohan %d\n", mtotal);
        } else {
            printf("Rohan %d\n", rtotal);
        }


        mtotal = 0;
        rtotal = 0;
    }
    return 0;
}
