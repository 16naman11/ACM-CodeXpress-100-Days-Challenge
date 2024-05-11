/*Meera was celebrating Diwali and had a pile of sweets. She couldn't fall asleep and was getting bored, so she started counting imaginary friends who wanted to take her Diwali sweets. Following activities were performed by Meera to prevent her friends from taking sweets away-

At every k-th friend she threw sweets to walk them away,
She tied hands of every l-th friend with a ribbon,
Meera playfully interacted with every m-th friend by pretending to tap their hands with a Diwali lantern, and
She threatened every n-th friend to give away her sweets
Due to above activities, every k-th, l-th, m-th and n-th friend didn't get the sweets.

If Meera counted a total of d friends, then how many of her imaginary friends were not able to get sweets ?

*/

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        long int d;
        scanf("%ld", &d);
        int k, l, m, n;
        scanf("%d %d %d %d", &k, &l, &m, &n);

        int totalcount = 0;

        for (int j = 1; j <= d; j++) {
            if (j % k == 0 || j % l == 0 || j % m == 0 || j % n == 0) {
                totalcount++;
            }
        }

        printf("%d\n", totalcount);
    }

    return 0;
}
