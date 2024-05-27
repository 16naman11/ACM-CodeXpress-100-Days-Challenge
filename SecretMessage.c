/*Secret agents communicate through a unique set of codes and symbols. Agent X, an expert cryptographer, has devised a typing challenge for fellow spies to ensure secure communication.

Agent X uses the American keyboard layout for typing secret messages.

The first row of the keyboard consists of the characters "qwertyuiop".
The second row consists of "asdfghjkl", and
The third row consists of "zxcvbnm".
Agent X gave some array of strings to the fellow spies and asked them to identify whether the string can be typed using letters from only one row of the American keyboard or not. Your task is to help Agent X in evaluating whether the answer provided by the fellow spies is correct or not by designing a program which will check the belonging of the given string to a particular row of the keyboard. Print "yes" if its possible else "no"
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        char str[1000];
        scanf("%s", str);
        int len=strlen(str);
        int count1=0,count2=0,count3=0;
        for(int i=0;i<len;i++){
            if(str[i]=='Q'||str[i]=='W'||str[i]=='E'||str[i]=='R'||str[i]=='T'||str[i]=='Y'||str[i]=='U'||str[i]=='I'||str[i]=='O'||str[i]=='P')
                count1++;
            else if(str[i]=='q'||str[i]=='w'||str[i]=='e'||str[i]=='r'||str[i]=='t'||str[i]=='y'||str[i]=='u'||str[i]=='i'||str[i]=='o'||str[i]=='p')
                count1++;
            else if(str[i]=='L'||str[i]=='K'||str[i]=='J'||str[i]=='H'||str[i]=='G'||str[i]=='F'||str[i]=='D'||str[i]=='S'||str[i]=='A')
                count2++;
            else if(str[i]=='l'||str[i]=='k'||str[i]=='j'||str[i]=='h'||str[i]=='g'||str[i]=='f'||str[i]=='d'||str[i]=='s'||str[i]=='a')
                count2++;
                else if(str[i]=='m'||str[i]=='n'||str[i]=='b'||str[i]=='v'||str[i]=='c'||str[i]=='x'||str[i]=='z')
                    count3++;
            else if(str[i]=='M'||str[i]=='N'||str[i]=='B'||str[i]=='V'||str[i]=='C'||str[i]=='X'||str[i]=='Z')
                    count3++;
                            
        }
        if(len==count1)
            printf("yes\n");
        else if(len==count2)
            printf("yes\n");
        else if(len==count3)
            printf("yes\n");
        else
            printf("no\n");
            
    }
    return 0;
}
