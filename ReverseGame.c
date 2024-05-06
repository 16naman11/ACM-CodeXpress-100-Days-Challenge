/*Ram and Priya are playing an amazing game where they take turns and give each other a name. They have to reverse the name given by them to each other from a particular position and speak aloud the new reversed word. Write a program to help them reverse the name.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int K;
        char S[1000],temp;
        scanf("%d",&K);
        scanf("%s", S);
        for(int i=0;i<K/2;i++){
            temp=S[i];
            S[i]=S[K-i-1];
            S[K-i-1]=temp;
        }
        printf("%s\n", S);
    }
    return 0;
}
