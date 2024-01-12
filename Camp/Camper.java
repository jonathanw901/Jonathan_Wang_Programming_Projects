/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package camp;

import java.util.Scanner;

/**
 *
 * @author jonathanwang
 */
public class Camper implements Comparable {
    String name;
    int age;
    char diet;
    
  public static int count=0;
  
  public Camper(String n){
      name = n;
  }
  // Constructor

  public Camper(Scanner f)
  {
    name=f.next();
    age=f.nextInt();
    diet=f.next().charAt(0);
  }

  // Accessor/Observer/getter

  public String getName() { return name; }
  public int getAge() { return age; }
  public char getDiet() { return diet; }

  public String toString()
  {
    return "Name: "+name+"\nAge: "+age+"\ndiet: "
      +diet;
  }

  public int compareTo(Object y)
  {
    if(y instanceof Camper)
    {
      Camper f=(Camper)y;
        return name.compareTo(f.getName());
    }
    else
      return 0; // not a Fish!
  }

  // Mutator/Transformer/setter



}
