/*You are a student at the prestigious Hero Academy, where you are training to become a pro hero. You have a special quirk that allows you to manipulate the numbers in any array. However, your quirk has a limitation: you can only change the numbers that are larger than a certain value to be equal to that value. For example, if the value is 5, you can change 6, 7, 8, etc. to 5, but you cannot change 4, 3, 2, etc.

One day, you are given a challenge by your teacher: you are given an array of numbers arr and a target number. You have to use your quirk to make the sum of the array as close as possible to the target number. If there are multiple ways to do this, you have to choose the smallest value that you can use to change the numbers.

Print the value which you are going to use for your quirk to make the sum of the array as close as possible to the target number.*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int a = 0; a<t; a++){
            int n = s.nextInt();
            int target = s.nextInt();
            
        int nums[] = new int[n];
            long sum = 0;
            int maxElement = Integer.MIN_VALUE;
            for(int i = 0; i<n; i++){
                nums[i] = s.nextInt();
                sum+= (long)nums[i];
                if(nums[i] > maxElement){
                    maxElement = nums[i];
                }
            }
        
            if(sum <= target){
                System.out.println(maxElement);
            }
            else{
                int x = Math.round((float)target/n);
                int y = target/n;
                
                if(Math.abs(target - n*x) == target - y){
                    System.out.println(Math.min(x,y));
                }
                else{
                System.out.println(x);
                }
            }
        }
    }
}