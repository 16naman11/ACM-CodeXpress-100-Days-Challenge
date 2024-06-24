/*Tweedle-Dee and Tweedle-Dum are in a fierce battle playing even-odd nim. This novel game is played on N heaps. Heap i contains ai stones.

Like normal nim, Tweedle-Dee and Tweedle-Dum alternate taking a positive number of stones from any single one of the heaps, and the player that can't remove stones loses. However Tweedle-Dee can only take an even number of stones, and Tweedle-Dum can only take an odd number of stones.

Alice doesn't want to wait until the end of the game, so she asks you to determine the winner of the game. Remember that Tweedle-Dee and Tweedle-Dum are legendary grandmasters of combinatorial games, so they always play optimally.*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int a = 0; a<t; a++){
            int n = s.nextInt();
            String player = s.next();
            String winner = "Dum";
            
            int heaps[] = new int[n];
            for(int i = 0; i<n; i++){
                heaps[i] = s.nextInt();
            }
            
            if(n == 1 && player.equals("Dee")){
                if(heaps[0] % 2 == 0){
                    winner = "Dee";
                }
            }
            System.out.println(winner);
        }
    }
}