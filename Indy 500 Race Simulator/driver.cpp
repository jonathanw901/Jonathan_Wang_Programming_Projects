// Driver Program
//
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#include <iostream>
#include <string>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function

#include "car.h"

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Input text file to read
    ifstream in("indy500.txt");

    string name;
    int speed;
    int control;
    
    // create array of 33 racecars
    car rc[33];
    
    // Read text file completely
    for (int i = 0; i < 33; i++)
    {
        // assign attributes of each racecar from each line
        in >> name >> speed >> control;
        rc[i].setName(name);
        rc[i].setSpeed(speed);
        rc[i].setControl(control);
        std::cout << rc[i].getName() << "\n";
        std::cout << rc[i].getSpeed() << "\n";
        std::cout << rc[i].getControl() << "\n";
    }

    // Get the system time.
    unsigned seed = time(0);
   
    // Seed the random number generator.
    srand(seed);

    // set the speed of the racecars based on control value
    for (int i = 0; i < 33; i++)
    {
        if (rc[i].getControl() > 5){
            int randNum = rand()%10 + 1;
            rc[i].setSpeed(rc[i].getSpeed() + rc[i].getControl()/randNum);
        } else {
            
        }
        std::cout << "Car " + to_string(i+1) + " speed is " + to_string(rc[i].getSpeed()) << "\n";
    }
    
    // find the fastest car, which is the winner
    car fastestCar;
    fastestCar = rc[0];
    for (int i = 0 ; i < 33; i++){
        if (fastestCar.getSpeed() < rc[i].getSpeed()){
            fastestCar = rc[i];
        }
    }
    std::cout << "Fastest car has speed of " + to_string(fastestCar.getSpeed()) + " and name is " + fastestCar.getName() << "\n";

    for (int i = 0 ; i < 33; i++){
        rc[i].setLapNumber(0);        
    }

    while (fastestCar.getLapNumber() < 200){
        for (int i = 0 ; i < 33; i++){
            rc[i].setLapNumber(rc[i].getLapNumber() + rc[i].getSpeed());
            if (rc[i].getName() == fastestCar.getName()){
                fastestCar.setLapNumber(rc[i].getLapNumber() + rc[i].getSpeed());
            }
            //std::cout << "Racing" + to_string(rc[i].getLapNumber()) << "\n";
            //std::cout << fastestCar.getName() << "\n";
        }
    }
    
    // find how many laps other cars have completed by the time the fastest car wins
    //int time = 200/fastestCar.getSpeed();
    for (int i = 0 ; i < 33; i++){
        //int lap;
        //rc[i].setLapNumber(rc[i].getSpeed() * time);
    
        if (rc[i].getName() != fastestCar.getName()){
            std::cout << "Car " + to_string(i+1) + " has finished " + to_string(rc[i].getLapNumber()) + " laps and name is " + rc[i].getName() << "\n";
        } else {
            std::cout << "Car " + to_string(i+1) + " has finished 200 laps and name is " + rc[i].getName() << "\n";
        }
        
    }
    
    std::cout << fastestCar.getName() + " has won the race!" + "\n";
    
	return 0;
}
