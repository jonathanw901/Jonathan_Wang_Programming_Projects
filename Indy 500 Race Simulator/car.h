// Header File
//
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#include <iostream>
#include <string>

// Class Declaration
class car
{
public:
    car(); // Default Constructor
    car(std::string n, int s, int c, int ln); // Non-Default Constructor
    ~car(); // Destructor
    // Setters
    void setName(std::string n);
    void setSpeed(int s);
    void setControl(int c);
    void setLapNumber(int ln);
    // Getters
    std::string getName();
    int getSpeed();
    int getControl();
    int getLapNumber();
    
private:
    // Trailing _ indicates class member.
    std::string name_;
    int speed_;
    int control_;
    int lapNumber_;
};
