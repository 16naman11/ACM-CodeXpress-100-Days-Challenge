/*You are the leader of a team of anime characters, each with a different level of skill. You want to train them to become stronger, so you hire some professional trainers who can help them improve. Each trainer has a certain amount of training power, which determines how much they can teach a character.

You can only pair up a character with a trainer if the character’s skill is not higher than the trainer’s power. Also, you can only pair up each character and each trainer once. You want to maximize the number of pairs you can make.

How many pairs can you form between your characters and the trainers?*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int ch, tr;
        scanf("%d %d", &ch, &tr);
        int a[ch], b[tr];

        for (int j = 0; j < ch; j++) {
            scanf("%d", &a[j]);
        }

        for (int k = 0; k < tr; k++) {
            scanf("%d", &b[k]);
        }

        qsort(a, ch, sizeof(int), compare);
        qsort(b, tr, sizeof(int), compare);

        int count = 0, x = 0, l = 0;

        while (x < tr && l < ch) {
            if (a[l] <= b[x]) {
                count++;
                l++;
                x++;
            } else {
                x++;
            }
        }

        printf("%d\n", count);
    }
    return 0;
}
