#/*Diwali is around the corner and you have to send greetings to your family and friends. You are given an array of strings representing Diwali greetings. However, these greetings are combined together, and you need to separate them into individual wishes. The greetings are joined using separator symbols which can be any character like- ‘ . ’ , ‘@’ etc . Your task is to split these strings and create and output a list of individual Diwali wishes.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

   int T;
    scanf("%d",&T);
    int len, count=0,start=0;
    for(int i=0;i<T;i++){
        char str[1000];
        scanf("%s", str);
        len=strlen(str);
        for(int j=0;j<len-1;j++){
            if(str[j]>='a' && str[j]<='z' || str[j]>='A' && str[j]<='Z' ){
                printf("%c", str[j]);
                start=1;
                count=0;
            }
            else
                count++;
            if(count==1 && start>0)
                printf("\n");
        }
        if(str[len-1]>='a' && str[len-1]<='z' || str[len-1]>='A' && str[len-1]<='Z' )
            printf("%c", str[len-1]);
        printf("\n");
    }
    return 0;
}
