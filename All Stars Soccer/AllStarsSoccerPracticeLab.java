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
public class AllStarsSoccerPracticeLab {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        SoccerPracticeManager practiceNeeds = new SoccerPracticeManager();
        practiceNeeds.getAllPlayers();
        practiceNeeds.getAllPositions();
        practiceNeeds.SoccerPracticeManager();
        String[] requirements = practiceNeeds.practiceLineUp();
        for (int index = 0; index < requirements.length; index++)
            System.out.println(requirements[index]);
        SoccerPracticeManager random = new SoccerPracticeManager();
        random.getAllPlayers();
        random.getAllPositions();
        random.SoccerPracticeManager();
        String[] rand = random.testRandomSkills();
        for (int index = 0; index < requirements.length; index++)
            System.out.println(rand[index]);
    } 
}
