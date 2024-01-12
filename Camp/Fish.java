/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package camp;

import java.util.*;

// Fish class

class Fish implements Comparable
{
  String name;
  String color;
  String species;
  int fins;

  public static int count=0;

  // Constructor
  public Fish(String n, String c, String s, int f)
  {
    name=n;
    color=c;
    species=s;
    fins=f;
    count++;
  }

  public Fish(Scanner f)
  {
    name=f.next();
    color=f.next();
    species=f.next();
    fins=f.nextInt();
    count++;
  }

  // Accessor/Observer/getter

  public String getName() { return name; }
  public String getColor() { return color; }
  public String getSpecies() { return species; }
  public int getFins() { return fins; }

  public String toString()
  {
    return "Fish: "+name+" color="+color+" species="
      +species+" # of fins="+fins;
  }

  public int compareTo(Object y)
  {
    if(y instanceof Fish)
    {
      Fish f=(Fish)y;
      if(fins<f.getFins())
        { return -1; }
      else if(fins==f.getFins())
        { return 0; }
      else
        { return 1; }
    }
    else
      return 0; // not a Fish!
  }

  // Mutator/Transformer/setter

  public void sharkAttack()
  {
    fins--;
    if(fins<0) { fins=0; }
  }

  public void seaweed() // eats radioactive seaweed
  {
    fins++;
    color="glowing "+color;
  }

}
