//Jonathan Wang
//Due 04-14-2023
//Camp

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package camp;

import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author jonathanwang
 */

//text file to use
///Users/jonathanwang/Downloads/Camp.txt

public class Camp {
    public static void main(String [] args) throws IOException{
        // user inputs text file
        System.out.println("Enter the path of the data file");
        Scanner cn = new Scanner (System.in);
        // scanner needs to be used to read text file
        String filename;
        filename = cn.nextLine();
        Scanner input = new Scanner (new FileReader(filename));
        // declares empty char variable since text file is read by character values
        char option = ' ';
        // declares new binary search tree
        Tree BinaryT = new BST();
        String name;
        // variables for finding total number of campers, total number of vegan campers, and their total age
        int totalAge = 0;
        int totalCamper = 0;
        int totalVegan = 0;
        System.out.println("\n");
        do{
            // scans next char in text file to determine which operation to do
            option = input.next().charAt(0);
            if (option == 'E'){
                // adds a camper
                Camper c = new Camper(input);
                BinaryT.insert(c);
                totalAge = totalAge + c.getAge();
                totalCamper++;
                if (c.getDiet() == 'V'){
                    totalVegan++;
                }
                String n = c.getName();
                System.out.println("Command: " + option);
                System.out.println(n + " added");
                System.out.println("Added a camper\n");
            }else if (option == 'W'){
                // removes a camper
                name = input.next();
                Camper c = (Camper) BinaryT.lookup(new Camper (name));
                BinaryT.delete(c);
                totalAge = totalAge - c.getAge();
                totalCamper--;
                if (c.getDiet() == 'V'){
                    totalVegan--;
                }
                System.out.println("Command: " + option);
                System.out.println(name + " deleted");
                System.out.println("Deleted a camper\n");
            }else if (option == 'D'){
                // prints name, age, and diet of current camper
                name = input.next();
                Camper c = (Camper) BinaryT.lookup(new Camper (name));
                String n = c.getName();
                int a = c.getAge();
                char d = c.getDiet();
                System.out.println("Command: " + option);
                System.out.println("Name: " + n);
                System.out.println("Age: "+a);
                System.out.println("Diet: "+d+ "\n");
            }else if (option == 'A'){
                // prints average age of campers by dividing their total age by their number, if there are not campers, prints no campers
                if (totalCamper == 0){
                    System.out.println("Command: " + option);
                    System.out.println("There are no campers\n");
                }else{
                    double averageAge = (double)totalAge/(double)totalCamper;
                    System.out.println("Command: " + option);
                    System.out.println("The average age of the campers is " + averageAge +"\n");
                }
            }else if (option == 'L'){
                // lists campers in alphabetical order, since binary search tree, inorder is alphabetical order
                System.out.println("Command: " + option);
                BinaryT.reset(BST.INORDER);
                while (BinaryT.hasNext()){
                    System.out.println(BinaryT.getNext());
                }    
                System.out.println("Campers listed in alphabetical order\n");
            }else if (option == 'V'){
                // prints number of vegan campers
                System.out.println("Command: " + option);
                System.out.println("The number of vegan campers is " + totalVegan +"\n");
            }else if (option == 'P'){
                // lists campers in preorder
                System.out.println("Command: " + option);
                BinaryT.reset(BST.PREORDER);
                while (BinaryT.hasNext()){
                    System.out.println(BinaryT.getNext());
                }
                System.out.println("Campers listed in preorder\n");
            }else{
                // displays end of program
                System.out.println("Command: Q");
                System.out.println("End of program");
            }
        
        }while(option != 'Q');
    }
}
