//Filename:  proj1.cpp
//Author:  Esquire At Large
//Date written: February 11th, 2008
//Program Description:  Enter and display information for a pet.

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "pet.h"
using namespace std;

//Function prototypes
int getValidInt(char * prompt);
//Pre-condition: Determines if user selection is valid. 
//Post-condition: Displays the validity of user selection.

void programIntro();
//Precondition:  None
//Post-condition:  Displays purpose of program.

int getMenuOption();
//Pre-condition: Received menu option.
//Post-condition: Displays menu option.

pet getPetInfo();
//Precondition:  None
//Postcondition:  Prompts user for pet information
//and creates and returns a pet object.

double getValidNonNegDouble(char* prompt);
//Precondition:  Determines if price is valid and non-negative.
//Postcondition:  Displays validity of price.


int main(){
	int menuOption;
	pet p;
	//Display program purpose
	programIntro();

	//Loop to enter and display pets
	do{
		menuOption = getMenuOption();
		switch(menuOption){
			case 1:  //Enter pet info 
				p = getPetInfo();
				cout << "Pet entered successfully.";
				cout << endl;
				break;
			case 2:  //Display pet info
				p.displayHdg();
				cout << p << endl;
				break;
			case 3:  //Exit program
				cout << "\nProgram terminating." << endl;
				break;
			default:  //Invalid menu option
				cout << "\nInvalid menu option...Please "
			              	<< "re-enter:\n";
				break;
		}
	}while(menuOption != 3); //end do-while

	return 0;

} //end main		
			
pet getPetInfo()
//Precondition:  None
//Postcondition:  Prompts user for pet info, creates
//and returns a pet object.
{
	const int MAX_CHAR = 80;
	char species[MAX_CHAR];
	char name[MAX_CHAR];
	double price;

	cout << "Enter species: ";
	cin.getline(species, MAX_CHAR);
	while(strlen(species) >= MAX_SPECIES){
		cout << "Species exceeds " << MAX_SPECIES -1
			<< " characters.  Please re-enter: ";
		cin.getline(species, MAX_CHAR);
	}
	
	cout << "Enter name: ";
	cin.getline(name, MAX_CHAR);
	while(strlen(name) >= MAX_NAME){
		cout << "Name exceeds " << MAX_NAME -1
			<< " characters.  Please re-enter: ";
		cin.getline(name, MAX_CHAR);
	}

	price = getValidNonNegDouble("Enter the price: ");

	pet p(species, name, price);

	return p;
}

double getValidNonNegDouble(char* prompt)
//Precondition:  Determines if price is valid and non-negative.
//Postcondition:  Displays validity of price.
{
	const int MAX = 80;
	char buffer[MAX];
	double d;
	cout << prompt;
	cin.getline(buffer, MAX);
	while(strlen(buffer) != strspn(buffer, ".0123456789"))
	{
		cout << "\nInvalid price, please re-enter: ";
		cin.getline(buffer, MAX);
	}
	d = atof(buffer);

	return d;
}

int getValidInt(char* prompt)
//Pre-condition: Determines if user selection is valid. 
//Post-condition: Displays the validity of user selection.
{ 
	const int MAX = 80;
	char buffer[MAX];
	int i;
	cout << prompt;
	cin.getline(buffer,MAX);
	while(strlen(buffer) != strspn(buffer, "-0123456789"))
	{
		cout << "\nInvalid integer, please re-enter: ";
		cin.getline(buffer, MAX);
	}
	i = atoi(buffer);
	return i;
}

void programIntro()
//Precondition:  None
//Post-condition:  Displays purpose of program.

{
	cout << "This program displays information about pets, and also "
	    << "\nallows for input of pet information.\n";
}

int getMenuOption()
//Pre-condition: Received menu option.
//Post-condition: Displays menu option.
{
	int menuOption;
	cout << "1:  Enter information about a pet.\n"
	    << "2:  Display information about a pet.\n"
            << "3:  Exit the program.\n";
	menuOption =	getValidInt("Enter a menu option from 1 to 3: ");	
	return menuOption;
}
