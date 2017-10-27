//Filename:  pet.cpp
//Author:  Esquire At Large
//Datewritten:  02/14/08 Valentine's Day
//Class description:

#include <iostream>
#include <cstring>
#include "pet.h"
#include <iomanip>
using namespace std;

pet::pet(char sp[], char nm[], double pr)
 //Precondition:  Species (sp) cannot exceed MAX_SPECIES-1 characters
 //and name(nm) cannot exceed MAX_NAME-1 characters
 //price (pr) cannot be negative.
 //Postcondition:  If sp and/or nm exceed length, they will be
 //truncated.  If pr is negative, 0 will be stored as price.
 //Otherwise, arguments will be stored in respective datamembers.
{	
	setPet(sp, nm, pr);
}

void pet::setPet(char sp[], char nm[], double pr)
//Precondition:  Species (sp) cannot exceed MAX_SPECIES-1 characters
//and name(nm) cannot exceed MAX_NAME-1 characters
//price (pr) cannot be negative.
//Postcondition:  If sp and/or nm exceed length, they will be
//truncated.  If pr is negative, 0 will be stored as price.
//Otherwise, arguments will be stored in respective datamembers.
{
	setSpecies(sp);
	setName(nm);
	setPrice(pr);
}

void pet::setSpecies(char sp[])
//Precondition:  Species(sp) length cannot exceed MAX_SPECIES-1 characters.     
//Postcondition:  If sp exceeds length, it will be truncated, otherwise it is  
//stored in species.
{
	if(strlen(sp)>=MAX_SPECIES){
		strncpy(species, sp, MAX_SPECIES-1);
		species[MAX_SPECIES-1]='\0';
		cerr<< "Species exceeded max length, was truncated."<<endl;
	}
	else
		strcpy(species,sp);
}

void pet::setName(char nm[])
//Precondition:  Name(nm) cannot exceed 20 characters.
//Postcondition:  If name does exceed 20 characters, it is truncated, otherwise
//it is stored in name.
{
	if(strlen(nm)>=MAX_SPECIES){
		strncpy(species, nm, MAX_SPECIES-1);
		species[MAX_SPECIES-1]='\0';
		cerr<< "Name exceeded max length, was truncated."<<endl;
	}
	else
		strcpy(name, nm);
}

void pet::setPrice(double pr)
//Precondition:  Price(pr) cannot be negative
//Postcondition:  If price(pr) is negative, 0 will be stored in price.
//Otherwise, pr will be stored in price.
{	
	if(pr<0){
		price=0;
		cerr<<"Price was negative, so reset to zero."<<endl;
	}
	else
		price = pr;
}

const char* pet::getSpecies() const
//Precondition:  None
//Postcondition:  Returns species.
{
	return species;
}

const char* pet::getName() const
//Precondition:  None
//Postcondition:  Returns name.
{
	return name;
}

double pet::getPrice() const
//Precondition:  None
//Postcondition:  Returns price.
{
	return price;
}

void pet::displayHdg() const
//Precondition:  None
//Postcondition:  Displays column headings.
{	
	cout << endl; //A space so it looks neat.

	cout << left << setw(MAX_SPECIES+3) <<"Species";
	cout << setw(MAX_NAME+1) << left <<  "Name";	
	cout << setw(10) << right <<  "Price" << endl;		
	cout << "--------------------------------------------";
	cout << "----------\n";
}

ostream& operator<<(ostream& out, const pet& p)
//Precondition: None
//Postcondition: Outputs the pet information
{

	out  <<  left << setw(MAX_SPECIES + 3) <<  p.species 
		<< setw(MAX_NAME+1) << left <<  p.name
		<< fixed << showpoint << setprecision(2)
		<< setw(10)<<  right  <<  p.price<< endl;


	return out;

}

bool pet::operator==(const pet& p) const
//Precondition:
//Postcondition:
{
	if(strcmp(species, p.species)==0 && strcmp(name, p.name) ==0)
		return true;
	else
		return false;
}

bool pet::operator<(const pet& p) const
//Postcondition:  Returns true if the compared arguments (species then name)
//are not equal.  Meaning the implicit argument is less than the explicit
//argument.
{
	if(strcmp(species, p.species) == 0){
		if(strcmp(name, p.name) < 0)
			return true;
		else
			return false;
	}
	else if(strcmp(species, p.species) < 0){
		return true;
	}
	else 
		return false;
}
