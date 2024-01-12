//Jonathan Wang
//Due 02-24-2023
//Wumpus

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Lion;

/**
 *
 * @author jonathanwang
 */
public class Rooms {
    
    int roomNumber;
    int adj1;
    int adj2;
    int adj3;
    boolean hasLion;
    boolean hasManEatingAnts;
    boolean hasLavaPit;
    boolean hasEagles;
    boolean hasAmmo;
    
    public int getRoomNum(){
        return roomNumber;
    }
    
    public int getAdjacent1(){
        return adj1;
    }
    
    public int getAdjacent2(){
        return adj2;
    }
    
    public int getAdjacent3(){
        return adj3;
    }
    
    public boolean getLion(){
        return hasLion;
    }
    
    public boolean getAnts(){
        return hasManEatingAnts;
    }
    
    public boolean getLava(){
        return hasLavaPit;
    }
    
    public boolean getEagles(){
        return hasEagles;
    }
    
    public void set (int roomNum, int adjacent1, int adjacent2, int adjacent3, boolean lion, boolean ants, boolean lava, boolean eagles, boolean ammo){
        roomNum = roomNumber;
        adjacent1 = adj1;
        adjacent2 = adj2;
        adjacent3 = adj3;
        lion = hasLion;
        ants = hasManEatingAnts;
        lava = hasLavaPit;
        eagles = hasEagles;
        ammo = hasAmmo;
    }
}
