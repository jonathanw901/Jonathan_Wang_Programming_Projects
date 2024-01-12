//Jonathan Wang
//Due 03-31-2023
//Sorts

package sorts2;

import java.io.*;
import java.util.*;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Arrays;
/**
 *
 * @author jonathanwang
 */
public class Sorts2{

    /**
     * @param args the command line arguments
     */
    
    // function for making deep copy, which is randomizing array for before every sort
    static Integer [] deepCopy (Integer[] A, int b){
        for (int k=0; k<b; k++){
            A[k] = (int)(Math.random()*b)+1;
        }
        return A;
    }        
    
    public static void main(String[] args) throws IOException{
        // TODO code application logic here
        // accepts number of integers to sort and makes an array of that size
        System.out.println("Enter the number of integers to sort");
        Scanner keyboard = new Scanner(System.in);
        int n = keyboard.nextInt();
        Integer[] numbers = new Integer[n];
        
        // bubble sort
        deepCopy (numbers, n);
        if (n<=100)
            System.out.println("Unsorted Array: " + Arrays.toString(numbers));
        int startTime = (int)System.currentTimeMillis();
        Sorts.bubble(numbers);
        int endTime = (int)System.currentTimeMillis();
        if (n<=100)
            System.out.println("Sorted Array: " + Arrays.toString(numbers));
        int duration = endTime- startTime;
        System.out.println("Elapsed time for this operation: " + duration + " milliseconds\n");
        
        // insert sort
        deepCopy (numbers, n);
        if (n<=100)
            System.out.println("Unsorted Array: " + Arrays.toString(numbers));
        startTime = (int)System.currentTimeMillis();
        Sorts.insertion(numbers);
        endTime = (int)System.currentTimeMillis();
        if (n<=100)
            System.out.println("Sorted Array: " + Arrays.toString(numbers));
        duration = endTime- startTime;
        System.out.println("Elapsed time for this operation: " + duration + " milliseconds\n");
        
        // select sort
        deepCopy (numbers, n);
        if (n<=100)
            System.out.println("Unsorted Array: " + Arrays.toString(numbers));
        startTime = (int)System.currentTimeMillis();
        Sorts.selection(numbers);
        endTime = (int)System.currentTimeMillis();
        if (n<=100)
            System.out.println("Sorted Array: " + Arrays.toString(numbers));
        duration = endTime- startTime;
        System.out.println("Elapsed time for this operation: " + duration + " milliseconds\n");
        
        // quick sort
        deepCopy (numbers, n);
        if (n<=100)
            System.out.println("Unsorted Array: " + Arrays.toString(numbers));
        startTime = (int)System.currentTimeMillis();
        Sorts.quick(numbers);
        endTime = (int)System.currentTimeMillis();
        if (n<=100)
            System.out.println("Sorted Array: " + Arrays.toString(numbers));
        duration = endTime- startTime;
        System.out.println("Elapsed time for this operation: " + duration + " milliseconds\n");
        
        // shell sort
        deepCopy (numbers, n);
        if (n<=100)
            System.out.println("Unsorted Array: " + Arrays.toString(numbers));
        startTime = (int)System.currentTimeMillis();
        Sorts.shell(numbers);
        endTime = (int)System.currentTimeMillis();
        if (n<=100)
            System.out.println("Sorted Array: " + Arrays.toString(numbers));
        duration = endTime- startTime;
        System.out.println("Elapsed time for this operation: " + duration + " milliseconds\n");
    }
    
}
