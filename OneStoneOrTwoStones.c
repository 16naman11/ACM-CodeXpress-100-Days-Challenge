/*Raju and Chutki are playing a game. There are two piles numbered 1 and 2. Pile 1 contains X stones while Pile 2 contains Y stones.

Raju starts the game.

In his turn, Raju can either remove 1 stone each from both the piles or remove 2 stones from pile 1.
On the other hand, Chutki, in her turn, can either remove 1 stone each from both the piles or remove 2 stones from pile 2.
The player who cannot make a move loses. Determine the winner if both players play optimally.*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    scanf("%d", &t);
    while(t--){
        long int p1,p2;
        scanf("%ld %ld",&p1,&p2);
        int start=0;
        while(1){
            if(start%2==0&&p1>=1&&p2>=1){
                p1--;
                p2--;
                start++;
            }
            else if(start%2==0&&p1>=2){
                p1-=2;
                start++;
            }
            else if(start%2==0){
                printf("Chutki\n");
                break;
            }
            if(start%2!=0 && p1>=1&&p2>=1){
                p1--;
                p2--;
                start++;
            }
            else if(start%2!=0&&p2>=2){
                p2-=2;
                start++;
            }
            else if(start%2!=0){
                printf("Raju\n");
                break;
            }
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
