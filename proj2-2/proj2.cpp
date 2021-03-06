//Filename:  proj2.cpp
//Author:  Esquire At Large
//Date written: February 11th, 2008
//Program Description:  Allows entry of pets and display of a list of pets.
//Also allows for entry and removal of different pets.

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "pet.h"
#include "ListException.h"
#include "list.h"
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

pet getSpeciesAndName();
//Similar to get pet info, except don't prompt for price and instead
//of pet p(species, name, price); code pet p(species, name);

int main(){
	int menuOption;
	pet p;
	list l;
	//Display program purpose
	programIntro();

	//Loop to enter and display pets
	do{
		menuOption = getMenuOption();
		switch(menuOption){
			case 1:  //Create and store pet into list. 
				p = getPetInfo();
				try{
					l.insert(p);
					cout << "Pet entered successfully.";
					cout << endl;
				}
				catch(ListException my_ex){
					cout << "Exception occurred: ";
					cout << my_ex.what() << endl;
				}
				break;
			case 2:  //Delete a pet from a list.
				p = getSpeciesAndName();
				try{
					l.remove(p);
					cout << "---------------------------" << endl;
					cout << "Pet removed successfully.";
					cout << "---------------------------" << endl;
					cout << endl;
				}
				catch(ListException my_ex){
					cout << "Exception occurred: ";
					cout << my_ex.what() << endl;
				}
				break;
			case 3: //Retrieve and display pet
				p= getSpeciesAndName();
				try{
					l.retrieve(p);
					p.displayHdg();
					cout << p << endl;
				}
				catch(ListException my_ex){
					cout << "Exception occurred: ";
					cout << my_ex.what()  << endl;
				}
				break;	
			case 4:  //Clear list.
				l.destroyList();
				cout << "---------------------------" << endl;
				cout << "List successfully cleared.";
				cout << "---------------------------" << endl;
				cout << endl;
				break;
			case 5:  //Display list.
				if(l.isEmpty()) {
					cout << "------------------------" << endl;
					cout << "List is empty." << endl;
					cout << "------------------------" << endl;
				}
				else{
					cout << l << endl;
					//Display ending lines here so they aren't repeated in the operator<< function.
					cout << "--------------------------------------------";
					cout << "----------" << endl;
				}
				break;
			case 6:  //Exit program
				cout << "\nProgram terminating." << endl;
				break;
			default:  //Invalid menu option
				cout << "\nInvalid menu option...Please "
			              	<< "re-enter:\n";
				break;
		}
	}while(menuOption != 6); //end do-while

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

pet getSpeciesAndName()
//Similar to get pet info, except don't prompt for price and instead
//of pet p(species, name, price); code pet p(species, name);
{
        const int MAX_CHAR = 80;
        char species[MAX_CHAR];
        char name[MAX_CHAR];
        
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

	pet p(species, name);

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
	cout << "This program displays a list of pets and also allows "
	    << "\nfor insertion and removal of pets.\n";
}

int getMenuOption()
//Pre-condition: Received menu option.
//Post-condition: Displays menu option.
{
	int menuOption;
	cout << endl;
	cout << "1:  Insert pet into list.\n"
	    << "2:  Delete a specific pet.\n"
	    << "3: Retrieve specific pet from list.\n"
	    << "4:  Clear the list.\n"
	    << "5:  Display list.\n"
            << "6:  Exit the program.\n";
	cout << endl;
	menuOption =	getValidInt("Enter a menu option from 1 to 6: ");	
	return menuOption;
}
