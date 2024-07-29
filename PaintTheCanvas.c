/*You are a painter who loves to create art. You have a 1-D canvas, where each pixel is either white or black. You can represent the canvas as a string pixels, where pixels[i] is either ‘W’ or ‘B’, indicating the color of the ith pixel. The characters ‘W’ and ‘B’ stand for white and black, respectively.

You want to create a masterpiece that has at least one streak of k consecutive black pixels. However, your canvas currently has some white pixels that you need to paint over.

In one stroke, you can paint over a white pixel and make it black.

Print the minimum number of strokes you need to make in order to create your masterpiece?

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    scanf("%d", &t);
    while(t--){
        int k;
        scanf("%d", &k);
        char s[10000];
        scanf("%s", s);
        int len=strlen(s);
        int min=10000;
        for(int i=0;i<len-k+1;i++){
            int count=0;
            for(int j=i;j<i+k;j++){
                if(s[j]=='W'){
                    count++;
                }
            }
            if(count<min){
                min=count;
            }
        }
        printf("%d\n",min);
    }
    return 0;
}
