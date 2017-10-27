//Filename: pet.h
//Author:  Esquire At Large
//Date written:  02/14/08 Valentine's Day
//Class description:  Stores information about pets...
#pragma once
#include <iostream>
using namespace std;

const int MAX_SPECIES = 16;
const int MAX_NAME = 21;

class pet{
	friend ostream& operator<<(ostream&, const pet&);
	//Precondition:  None
	//Postcondition:  Outputs pet information in column form.
public:	
	pet(char sp[]="", char nm[]="", double pr=0);
	//Precondition:  Species (sp) cannot exceed MAX_SPECIES-1 characters
	//and name(nm) cannot exceed MAX_NAME-1 characters
	//price (pr) cannot be negative.
	//Postcondition:  If sp and/or nm exceed length, they will be 
	//truncated.  If pr is negative, 0 will be stored as price.
	//Otherwise, arguments will be stored in respective datamembers.
	void setPet(char sp[]="", char nm[]="", double pr=0);
	//Precondition:  Species (sp) cannot exceed MAX_SPECIES-1 characters
	//and name(nm) cannot exceed MAX_NAME-1 characters
	//price (pr) cannot be negative.
	//Postcondition:  If sp and/or nm exceed length, they will be
	//truncated.  If pr is negative, 0 will be stored as price.
	//Otherwise, arguments will be stored in respective datamembers.
	void setSpecies(char sp[]="");
	//Precondition:  Species(sp) length cannot exceed MAX_SPECIES-1
	// characters.
	//Postcondition:  If sp exceeds length, it will be truncated, otherwise
	//it is stored in species.
	void setName(char nm[]="");
	//Precondition:  Name length cannot exceed MAX_NAME-1 characters.
	//Postcondition:  If nm exceeds length, it will be truncated, otherwise
	//it is stored in name.
	void setPrice(double pr=0);
	//Precondition:  Price(pr) cannot be negative
	//Postcondition:  If price(pr) is negative, 0 will be stored in price.
	//Otherwise, pr will be stored in price.
	const char* getSpecies() const;
	//Precondition:  None
	//Postcondition:  Returns species.
	const char* getName() const;
	//Precondition:  None
	//Postcondition:  Returns name.
	double getPrice() const;
	//Precondition:  None
	//Postcondition:  Returns price.
	void displayHdg() const;
	//Precondition:  None
	//Postcondition:  Displays column headings.
	bool operator==(const pet&) const;
	//Precondition: Intakes a pet's species and name.
	//Postcondition: Compares the species of two pets (and if equal)
	//the names, to determine if they are equal, and if so, returns true.
	bool operator<(const pet&) const;
	//Postcondition: Returns true if the compared arguments
	//(species then name) are not equal.  Meaning the implicit argument
	//is less than the explicit one.
private:
	char species[MAX_SPECIES];
	char name[MAX_NAME];
	double price;
}; 
