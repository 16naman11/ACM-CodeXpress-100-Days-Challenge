/*It's Diwali time, that means fun time! Enjoying with the family, playing interesting games and eating a lot of delicious sweets. And the flavor of the season is always our very own favorite soan papadi! That we all love to eat.

Imagine you and your family members are playing an amazing game of passing soan papadi. In this game your n members of the family are standing in a line labeled from 1 to n. The first person in the line is holding the packet of soan papdi initially. Every second, the person holding the packet passes it to the next person standing in the line. Once the packet reaches the end of the line, the direction changes, and people continue passing the packet in the opposite direction.

For example, once the packet of soan papdi reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.

Given the two positive integers n and time, return the position of the person who wins the game and get the packet of soan papdi after time seconds.*/

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int n, t;
        scanf("%d %d", &n, &t);
        int j=1;
        int forward=1;
        while(t!=0){
            if(j==n){
                forward=0;
            }
            else if(j==1){
                forward=1;
            }
            if(forward){
                j++;
                t--;
            }
            else{
                j--;
                t--;
            }
        }
        printf("%d\n", j);
        
    }

    return 0;
}