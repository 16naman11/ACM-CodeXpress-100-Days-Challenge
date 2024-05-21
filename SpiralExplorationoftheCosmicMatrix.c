/*Suppose you have a cosmic matrix of size m x n, where each element represents a different celestial object or phenomenon. How would you traverse the matrix in a spiral order, starting from the top-left corner and moving clockwise, to observe all the wonders of the universe?

You can imagine the cosmic matrix as a rectangular patch of the night sky, where each cell contains a star, a planet, a galaxy, or any other cosmic entity.
To traverse the matrix in a spiral order, you would need to follow a pattern of moving right, down, left, and up, while reducing the number of steps in each direction by one after every two turns.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int m,n;
        scanf("%d %d",&m,&n);
        long int a[m][n];
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                scanf("%ld",&a[j][k]);
            }
        }
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom&&left<=right){
            for(int b=left;b<=right;b++){
                printf("%ld ", a[top][b]);
            }
            top++;
            
            for(int c=top;c<=bottom;c++){
                printf("%ld ", a[c][right]);
            }
            right--;
            
            if(top<=bottom){
                for(int d=right;d>=left;d--){
                    printf("%ld ", a[bottom][d]);
                }
            }
            bottom--;
            
            if(left<=right){
                for(int e=bottom;e>=top;e--){
                    printf("%ld ", a[e][left]);
                }
            }
            left++;
        }
        printf("\n");
        
    }
    return 0;
}
