//
//  JavaComparator.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 11/03/2017.
//
//  https://www.hackerrank.com/challenges/java-comparator

package it.hackerrank.datastructures;

import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

class Checker implements Comparator<Player> {

	public int compare(Player playerOne, Player playerTwo) {
		
		if (playerOne.score < playerTwo.score) {
			
			return 1;
		} else {
			
			if (playerOne.score == playerTwo.score) {
				
				return playerOne.name.compareTo(playerTwo.name);
			}
			
			return -1;
		}
	}
}

class Player{
	
    String name;
    int score;
    
    Player(String name, int score){
        this.name = name;
        this.score = score;
    }
}

class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        Player[] player = new Player[n];
        Checker checker = new Checker();
        
        for(int i = 0; i < n; i++){
            player[i] = new Player(scan.next(), scan.nextInt());
        }
        scan.close();
     
        Arrays.sort(player, checker);
        for(int i = 0; i < player.length; i++){
            System.out.printf("%s %s\n", player[i].name, player[i].score);
        }
    }
}
