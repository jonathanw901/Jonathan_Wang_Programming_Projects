//Jonathan Wang
//Due 02-24-2023
//Wumpus

//translation guide for skinning game:
//lion is wumpus
//fields are rooms
//man eating ants are spiders
//lava pits are pits
//eagles are bats (bonus)
//ammo is shots (bonus)

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package Lion;

import java.io.*;
import java.util.*;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;
///Users/jonathanwang/Documents/Butler/Classes 2023/CS248/Programming Projects/Wumpus/03-13-23/LionFields.txt
/**
 *
 * @author jonathanwang
 */
public class Lion {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        // TODO code application logic here
        // gets fields from text file
        String roomCount;
	    Scanner cn = new Scanner (System.in);
	    System.out.println("Enter the path of the field file");
	    roomCount = cn.nextLine();
	    Scanner room = new Scanner (new FileReader(roomCount));
        // r is number of fields
        int r = room.nextInt();
	Rooms [] rooms;
        rooms = new Rooms[r+1];
        //System.out.println(r);
        // algorithms to randomly decide which field numbers get which obstacles
        int lionNum = 2 + (int)(Math.random()*((r-2)+1));
        int antNum1 = 2 + (int)(Math.random()*((r-2)+1));
        while (antNum1 == lionNum){
            antNum1 = 2 + (int)(Math.random()*((r-2)+1));
        }
        int antNum2 = 2 + (int)(Math.random()*((r-2)+1));
        while (antNum2 == lionNum || antNum2 == antNum1){
            antNum2 = 2 + (int)(Math.random()*((r-2)+1));
        }
        int lavaNum1 = 2 + (int)(Math.random()*((r-2)+1));
        while (lavaNum1 == lionNum || lavaNum1 == antNum1 || lavaNum1 == antNum2){
            lavaNum1 = 2 + (int)(Math.random()*((r-2)+1));
        }
        int lavaNum2 = 2 + (int)(Math.random()*((r-2)+1));
        while (lavaNum2 == lionNum || lavaNum2 == antNum1 || lavaNum2 == antNum2 || lavaNum2 == lavaNum1){
            lavaNum2 = 2 + (int)(Math.random()*((r-2)+1));
        }
        int eaglesNum = 2 + (int)(Math.random()*((r-2)+1));
        while (eaglesNum == lionNum || eaglesNum == antNum1 || eaglesNum == antNum2 || eaglesNum == lavaNum1 || eaglesNum == lavaNum2){
            eaglesNum = 2 + (int)(Math.random()*((r-2)+1));
        }
        int ammoNum = 2 + (int)(Math.random()*((r-2)+1));
        while (ammoNum == lionNum || ammoNum == antNum1 || ammoNum == antNum2 || ammoNum == lavaNum1 || ammoNum == lavaNum2 || ammoNum == eaglesNum){
            ammoNum = 2 + (int)(Math.random()*((r-2)+1));
        }
        // algorithms to assign obstacles to fields
        for (int i = 1; i <= r; i++) {
            rooms[i] = new Rooms();
            rooms[i].roomNumber = room.nextInt();
            //System.out.println(i);
            rooms[i].adj1 = room.nextInt();
            //System.out.println(room1.adj1);
            rooms[i].adj2 = room.nextInt();
            //System.out.println(room1.adj2);
            rooms[i].adj3 = room.nextInt();
            //System.out.println(room1.adj3);
            if (i == lionNum){
                rooms[i].hasLion = true; 
                //System.out.println(i + "lion");
            } else {
                rooms[i].hasLion = false;
            }
            if (i == antNum1 || i == antNum2){
                rooms[i].hasManEatingAnts = true; 
                //System.out.println(i + "ants");
            } else {
                rooms[i].hasManEatingAnts = false;
            }
            if (i == lavaNum1 || i == lavaNum2){
                rooms[i].hasLavaPit = true; 
                //System.out.println(i + "lava");
            } else {
                rooms[i].hasLavaPit = false;
            }
            if (i == eaglesNum){
                rooms[i].hasEagles = true; 
                //System.out.println(i + "eagles");
            } else {
                rooms[i].hasEagles = false;
            }
            if (i == ammoNum){
                rooms[i].hasAmmo = true; 
                //System.out.println(i + "ammo");
            } else {
                rooms[i].hasAmmo = false;
            }
            
        }
        // start of game
        System.out.println("Welcome to hunt the lion!");
        int currentRoom = 1;
        boolean gameOver = false;
        int shots = 3;
        while (gameOver == false){
            // while game is still in play
            // displays info such as which field, shots remaining, adjacent field numbers, and obstacles nearby
            System.out.println("You are in field " + currentRoom);
            System.out.println("You have " + shots + " shots remaining");
            int adjacent1 = rooms[currentRoom].adj1;
            int adjacent2 = rooms[currentRoom].adj2;
            int adjacent3 = rooms[currentRoom].adj3;
            System.out.println("Your adjacent fields are " + adjacent1 + ", " + adjacent2 + ", and " + adjacent3);
            if (rooms[rooms[currentRoom].adj1].hasLion == true || rooms[rooms[currentRoom].adj2].hasLion == true || rooms[rooms[currentRoom].adj3].hasLion == true){
                System.out.println("You smell some lion");
            } 
            if (rooms[rooms[currentRoom].adj1].hasManEatingAnts == true || rooms[rooms[currentRoom].adj2].hasManEatingAnts == true || rooms[rooms[currentRoom].adj3].hasManEatingAnts == true){
                System.out.println("You hear some clicking of the man eating ants");
            } 
            if (rooms[rooms[currentRoom].adj1].hasLavaPit == true || rooms[rooms[currentRoom].adj2].hasLavaPit == true || rooms[rooms[currentRoom].adj3].hasLavaPit == true){
                System.out.println("You feel the warmth from a lava pit");
            } 
            if (rooms[rooms[currentRoom].adj1].hasEagles == true || rooms[rooms[currentRoom].adj2].hasEagles == true || rooms[rooms[currentRoom].adj3].hasEagles == true){
                System.out.println("You hear the eagles calling");
            } 
            if (rooms[rooms[currentRoom].adj1].hasAmmo == true || rooms[rooms[currentRoom].adj2].hasAmmo == true || rooms[rooms[currentRoom].adj3].hasAmmo == true){
                System.out.println("You smell some gunpowder from an ammo refill station");
            } 
            // algorithm if field has lion (immediately lose)
            if (rooms[currentRoom].hasLion == true){
                System.out.println("You lose! You are eaten by the lion");
                gameOver = true;
            // algorithm if field has man eating ants (immediately lose)
            } else if (rooms[currentRoom].hasManEatingAnts == true){
                System.out.println("You lose! You are eaten by the man eating ants");
                gameOver = true;
            // algorithm if field has lava pit (immediately lose)
            } else if (rooms[currentRoom].hasLavaPit == true){
                System.out.println("You lose! You fall into a lava pit");
                gameOver = true;
            // algorithm if field has eagles
            } else if (rooms[currentRoom].hasEagles == true){
                // picks field number to move to
                int nextRoom = currentRoom;
                while (nextRoom == currentRoom){              
                    nextRoom = 1 + (int)(Math.random()*((r-1)+1));
                }
                currentRoom = nextRoom;
                System.out.println("The eagles fly you to field " + currentRoom);
                gameOver = false;
            // algorithm if field has ammo refill
            } else if (rooms[currentRoom].hasAmmo == true){
                shots = 3;
                System.out.println("Your shots are refilled to 3");
                gameOver = false;
                System.out.println("[M]ove or [S]hoot?");
                Scanner keyboard = new Scanner(System.in);
                String MorS = keyboard.next();
                if ("s".equals(MorS)){
                    // to shoot
                    if (shots > 0){
                        System.out.println("Which field?");
                        int whichRoom = keyboard.nextInt();
                        if (whichRoom == rooms[currentRoom].adj1){
                            if (rooms[rooms[currentRoom].adj1].hasLion == true){
                                System.out.println("You win!");
                                gameOver = true;
                            }else{
                                gameOver = false;
                                shots--;
                                System.out.println("You lost a shot");
                            }
                        } else if (whichRoom == rooms[currentRoom].adj2){
                            if (rooms[rooms[currentRoom].adj2].hasLion == true){
                                System.out.println("You win!");
                                gameOver = true;
                            }else{
                                gameOver = false;
                                shots--;
                                System.out.println("You lost a shot");
                            }
                        } else if (whichRoom == rooms[currentRoom].adj3){
                            if (rooms[rooms[currentRoom].adj3].hasLion == true){
                                System.out.println("You win!");
                                gameOver = true;
                            }else{
                                gameOver = false;
                                shots--;
                                System.out.println("You lost a shot");
                            }
                        }else{
                            // cannot shoot if no shots are remaining
                            System.out.println("You can't shoot");
                            gameOver = false;
                        }
                
                
                } else if ("m".equals(MorS)){
                    // to move fields
                    System.out.println("Which field?");
                    int whichRoomToMove = keyboard.nextInt();
                    if (whichRoomToMove == rooms[currentRoom].adj1 || whichRoomToMove == rooms[currentRoom].adj2 || whichRoomToMove == rooms[currentRoom].adj3){
                        currentRoom = whichRoomToMove;
                        System.out.println(currentRoom);
                    } else {
                        // player has to pick an adjacent field if he chooses a field that is not adjacent to the current one
                        System.out.println("Pick an adjacent field");
                        gameOver = false;
                    }
                } else {
                    // if player does not shoot or move, he has to pick to shoot or move, so while loop is repeated
                    System.out.println("You have to [M]ove or [S]hoot");
                    gameOver = false;
                }
            } else {
                System.out.println("[M]ove or [S]hoot?");
                Scanner keys = new Scanner(System.in);
                String MoS = keys.next();
                if ("s".equals(MoS)){
                    // to shoot
                    if (shots > 0){
                        System.out.println("Which field?");
                        int whichRoom = keys.nextInt();
                        if (whichRoom == rooms[currentRoom].adj1){
                            if (rooms[rooms[currentRoom].adj1].hasLion == true){
                                System.out.println("You win!");
                                gameOver = true;
                            }else{
                                gameOver = false;
                                shots--;
                                System.out.println("You lost a shot");
                            }
                        } else if (whichRoom == rooms[currentRoom].adj2){
                            if (rooms[rooms[currentRoom].adj2].hasLion == true){
                                System.out.println("You win!");
                                gameOver = true;
                            }else{
                                gameOver = false;
                                shots--;
                                System.out.println("You lost a shot");
                            }
                        } else if (whichRoom == rooms[currentRoom].adj3){
                            if (rooms[rooms[currentRoom].adj3].hasLion == true){
                                System.out.println("You win!");
                                gameOver = true;
                            }else{
                                gameOver = false;
                                shots--;
                                System.out.println("You lost a shot");
                            }
                        }else{
                            // cannot shoot if no shots are remaining
                            System.out.println("You can't shoot");
                            gameOver = false;
                        }
                }else{
                    System.out.println("You can't shoot");
                    gameOver = false;
                }
                
                
                } else if ("m".equals(MoS)){
                    // to move fields
                    System.out.println("Which field?");
                    int whichRoomToMove = keys.nextInt();
                    
                    if (whichRoomToMove == rooms[currentRoom].adj1 || whichRoomToMove == rooms[currentRoom].adj2 || whichRoomToMove == rooms[currentRoom].adj3){
                        currentRoom = whichRoomToMove;
                        System.out.println(currentRoom);
                    } 
                    else {
                        // player has to pick an adjacent field if he chooses a field that is not adjacent to the current one
                        System.out.println("Pick an adjacent field");
                        gameOver = false;
                    }
                } else {
                    // if player does not shoot or move, he has to pick to shoot or move, so while loop is repeated
                    System.out.println("You have to [M]ove or [S]hoot");
                    gameOver = false;
                }
            }            
            }
        }        
    }
    
    
}
