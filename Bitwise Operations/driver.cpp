// Driver Program
//
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "bitarray.h"
#include "set.h"
#include "dictionary.h"

int main()
{
    char test[] = "test";

    //phase 5
    Dictionary dict;
    dict.initialize(test, strlen(test));
    //dict.printLookupTable(std::cout);
    std::cout << "Rank: " << dict.rank(31) << "\n";
    /*
    //Phase 4
    BitArray bitArray(0);
    bitArray.initialize(test, strlen(test));
    bitArray.print();
    Dictionary dict;
    dict.initialize(test, strlen(test));
    std::cout << "Rank: " << dict.rank(31) << "\n";
    std::cout << "Rank Range (15-31): " << dict.rank_range(15, 31)<<"\n";
    std::cout << "Select (5,1): " << dict.select(5) << "\n";
    std::cout << "Select Range (0,15,2,1): " << dict.select_range(0, 15, 2, 1)<<"\n";
    */
    /*
    //Phase 3
    Set bitArray;
    bitArray.initialize(test, strlen(test));
    bitArray.getData().print();
    std::cout << "Bitarray A:\n";
    //std::cout << "Cardinality: " << bitArray.getCardinality() << "\n";
    //test union
    char tset[] = "tset";
    Set bitArray2;
    bitArray2.initialize(tset, strlen(tset));   
    std::cout << "Bitarray B:\n";
    bitArray2.getData().print();
    std::cout << "A Union B:\n";
    bitArray.setUnion(bitArray2);
    bitArray.getData().print();
    */
    /*
    //std::cout << "Number of Bits: " << bitArray.getData().bytes() << std::endl;
    //std::cout <<"2 Position: " << bitArray.getData().get8(2) << std::endl;
    //test flip
    std::cout << "Flip position 0:\n";
    bitArray.getData().flip(0);
    bitArray.getData().print();
    */
    /*
    //test set
    std::cout << "Set position 0 to 1:\n";
    bitArray.getData().set(0, 1);
    bitArray.getData().print();
    std::cout << "Set position 0 to 0:\n";
    bitArray.getData().set(0, 0);
    bitArray.getData().print();
    */
    /*
    //test compliment
    std::cout << "Complement:\n";
    bitArray.getData().complement();
    bitArray.getData().print();
    //test clear
    bitArray.getData().clear();
    bitArray.getData().print();
    */
	return 0;
}