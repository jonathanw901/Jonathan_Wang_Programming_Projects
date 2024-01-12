/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg6.all.stars.soccer.practice.lab;

/**
 *
 * @author jonat
 */
public class SoccerPracticeManager {
    
    private String[] allPlayers;
    private String[] allPositions;

    public String[] getAllPlayers() {
        return allPlayers;
    }

    public String[] getAllPositions() {
        return allPositions;
    }
    
    public void SoccerPracticeManager(){
    allPositions = new String[5];
    allPositions[0] = "Keeper";
    allPositions[1] = "Midfielder";
    allPositions[2] = "Striker";
    allPositions[3] = "Forward";
    allPositions[4] = "Defender";
    
    allPlayers = new String[5];
    allPlayers[0] = "Harry Kane";
    allPlayers[1] = "Cristiano Ronaldo";
    allPlayers[2] = "Eden Hazard";
    allPlayers[3] = "Diego Maradona";
    allPlayers[4] = "Lionel Messi";
    }
    
    public String[] practiceLineUp(){
        String[] practiceNeeds = new String[25];
        int index = 0;
        for (String playerName : allPlayers){
            for (String position : allPositions){
                practiceNeeds[index] = playerName + " : " + position;
                index++;
            }
        }
        return practiceNeeds;
    }
    
    public String[] testRandomSkills(){
        String[] random = new String [2];
        int randNum1 = (int)(Math.random() * 5);
        random[0] = allPlayers[randNum1];
        randNum1 = (int)(Math.random() * 5);
        random[1] = allPositions[randNum1];
        return random;
    }
}
