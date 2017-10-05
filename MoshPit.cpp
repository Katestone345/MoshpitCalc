// MoshPit.cpp.cpp : Defines the entry point for the console application.
////MoshPit.cpp : Defines the entry point for the console application.
//Purpose: This program will read in information from user inputs
//Purpose cont: This program will also calculate the safest amount of people able to mosh in a mosh pit
////////////////////////////////////////////////////////////////////////////////
//Author: Katlynn Stone
//Format of the file is:

//Order item, is , outside length, outside width, Mosher size, safety value, and total moshers able to dance in the moshpit

//There is no output file for this assignment.


//This program has been written by Katlynn Stone

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	//Declare outside measurement variables
	//Outside variables of the mosh pit will have an 'O' Characteristic attached to it

	double OMLength;
	double OMWidth;

	//Declare inside measurement variables
	//Inside variables of the mosh pit will have an 'I' Characteristic attached to it
	double IMLength;
	double IMNorth;
	double IMSouth;
	double IMWest;
	double IMEast;

	//Set a variable for the user input for mosher size and different seperation values
	// Seperation values between A,B,C, and Q.
	// Sizes will range between L,XL,XXL, and Q to exit the program.
	string mosherSize;
	double SizeValue;
	string mosherSafety;
	double SafetyValue;

	//Set variables for the areas needed in order to calculate precise measurements
	double OArea;
	double TAreaEW;
	double TAreaNS;


	//Set variables for the area total of the moshers size
	double MosherArea;
	double TotalMoshersEW;
	double TotalMoshersNS;
	double TotalMoshers;

	//Gather user input for length and width of mosh pit
	cout << "Please enter the length (in feet) of the mosh pit:\t";
	cin >> OMLength;
	cout << "Please enter the width (inf feet) of the mosh pit:\t";
	cin >> OMWidth;

	//Gather user information for the thickness of the wall 
	cout << "Please enter the thickness (in feet) of the top of the North side of the barricade:\t";
	cin >> IMNorth;
	cout << "Please enter the thickness (in feet) of the top of the South side of the barricade:\t";
	cin >> IMSouth;
	cout << "Please enter the thickness (in feet) of the top of the West side of the barricade:\t";
	cin >> IMWest;
	cout << "Please enter the thickness (in feet) of the top of the East side of the barricade:\t";
	cin >> IMEast;
	cout << "Please enter a safety rating (A,B,C or Q to quit):\t";
	cin >> mosherSafety;
	
	//Transform user input to all caps, will be easier to execute later in the program
	transform(mosherSafety.begin(), mosherSafety.end(), mosherSafety.begin(), ::toupper);
	
	cout << "Please enter the size of the mosher (L,XL,XXL, or Q to quit):\t";
	cin >> mosherSize;
	
	//Transform user input to all caps, will be easier to execute later in the program
	transform(mosherSize.begin(), mosherSize.end(), mosherSize.begin(), ::toupper);

	//Run through the user input for mosherSafety
	if (mosherSafety == "A") {
		SafetyValue = 2.5;
	}
	else if (mosherSafety == "B") {
		SafetyValue = 1.5;
	}
	else if (mosherSafety == "C") {
		SafetyValue = 0.5;
	}
	else {
		exit(0);
	}

	//Run user input for mosherSize
	if (mosherSize == "L") {
		SizeValue = 1.5;
	}
	else if (mosherSize == "XL") {
		SizeValue = 2.5;
	}
	else if (mosherSize == "XXL") {
		SizeValue = 3.5;
	}
	else {
		exit(0);
	}

	//Calculate the amount of moshers that can fit safely into the mosh pit
	//First calculate the area of the outside of the arena
	OArea = OMWidth * OMLength;
	
	//Now we will subtract the thickness of each wall from the outside arena area
	TAreaNS = OMLength - (IMSouth + IMNorth);
	TAreaEW = OMWidth - (IMEast + IMWest);


	//Now we will calculate the total amount of moshers that can mosh in the moshpit while moshing safely.
	MosherArea = SizeValue + SafetyValue;

	//Moshers able to fit east to west
	TotalMoshersEW = TAreaEW / MosherArea;

	//Moshers able to fit north to south
	TotalMoshersNS = TAreaNS / MosherArea;

	//Total moshers able to mosh
	TotalMoshers = TotalMoshersEW * TotalMoshersNS;

	//Lets read back accurate measurements to the user
	cout << "The number of moshers that can fit East to West is: " << TotalMoshersEW << "." << endl;
	cout << "The number of moshers that can fit North to South is: " << TotalMoshersNS << "." << endl;
	cout << "The number of moshers that will fit in a barricade " << OMWidth << " feet wide by " << OMLength << " feet long is " << TotalMoshers << endl;



	system("pause");

    return 0;
}

