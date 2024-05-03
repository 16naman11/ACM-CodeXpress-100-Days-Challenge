/*Diwali, the festival of lights, is here, and Meera is getting ready to illuminate her house. She has a series of lights, each representing a different Diwali lamp. The brightness of each lamp is symbolized by a positive integer in an array. Meera wants to create a stunning Diwali display, and she can achieve this by rotating the array in a specific direction and a certain number of times. The direction and the number of rotations are determined by two integers: direction and noOfRotations.

Rules for rotation:

The direction can have value either 0 or 1
If direction is 0, Meera should rotate the array to the left by noOfRotations time, and
If direction is 1, Meera should rotate the array to the right by noOfRotations time*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i,j,k,l,T, dir,nor,N,temp;
    long int L[10000];
    scanf("%d", &T);
    for(i=0;i<T;i++){
        i=0;
        j=0;
        k=0;
        l=0;
        scanf("%d %d %d", &dir, &nor, &N);
        //scanf("%d", &nor);
        //scanf("%d", &N);
        if(nor<=N){
            for(l=0;l<N;l++){
            scanf("%ld", &L[l]);
        }
        if(dir==1){
            for(i=0;i<nor;i++){
                temp=L[N-1];
                for(j=N-1;j>0;j--){
                    L[j]=L[j-1];
                }
                L[0]=temp;
            }
        }
        else if(dir==0){
            for(i=0;i<nor;i++){
                temp=L[0];
                for(j=0;j<N-1;j++){
                    L[j]=L[j+1];
                }
                L[N-1]=temp;
            }
        }
        }
        
        for(k=0;k<N;k++){
            printf("%ld",L[k]);
            if(k<N-1){
                printf(" ");
            }
        }
        printf("\n");
        
    } 
    return 0;
}
