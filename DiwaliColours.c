/*Diwali is a festival of lights celebrated by Hindus in India and around the world. On this occasion, people decorate their homes with colorful lamps, candles and electric lights. Ramesh is excited to celebrate Diwali, he decorates his living room with an array of N lights L. Each light has some color value L[i]. Ramesh wants to know whether the number of lights that have even color value is greater than the number of lights that have odd color value. He decides to write a program that takes the array L as an input and prints “Yes” if the count of lights with even value is strictly greater than the count of lights with odd value, and prints “No” otherwise. Can you help him write the program?*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

   int T,N,L[1000],i,j,odd,even;
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%d", &N);
        even=0;
        odd=0;
        for(j=0;j<N;j++){
            scanf("%d", &L[j]);
            if(L[j]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(even>odd){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        } 
    }
    return 0;
}
