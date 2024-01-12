// Class Implementation
//
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#include <iostream>
#include <fstream>
#include <string>
#include "car.h"
// Default Constructor
car::car()
{
    name_ = "Default";
    speed_ = 0;
    control_ = 0;
    lapNumber_ = 0;
}

// Non-default Constructor
car::car(std::string n, int s, int c, int ln)
{
    name_ = n;
    speed_ = s;
    control_ = c;
    lapNumber_ = ln;
}

// Destructor
car::~car()
{
}

// Setters

void car::setName(std::string n){
    name_ = n;
}

void car::setSpeed(int s){
    speed_ = s;
}

void car::setControl(int c){
    control_ = c;
}

void car::setLapNumber(int ln){
    lapNumber_ = ln;
}

// Accessor Methods or Getters

std::string car::getName()
{
    return name_;
}

int car::getSpeed()
{
    return speed_;
}

int car::getControl()
{
    return control_;
}

int car::getLapNumber()
{
    return lapNumber_;
}
