//Filename:  list.h
//Author:  Esquire At Large
//Date written:  February 28th, 2008
//Class description:  Contains function declarations for list containing
//pets.

#pragma once
#include "ListException.h"
#include "pet.h"
#include "iostream"
#include "ostream"
using namespace std;
const int MAX_SIZE = 25;

class list{

	friend ostream& operator<<(ostream&, const list&);
	//Precondition:
	//Postcondition:

public:
	list();
	//Precondition: None
	//Postcondition: Sets size to zero.

	bool isEmpty() const;
	//Precondition: None
	//Postcondition: Returns boolean value to determine if size is
	//equivalent to zero, meaning that the list contains no items.

	bool isFull() const;
	//Precondition: None
	//Postcondition: Returns boolean value to determine if size is
	//equivalent to MAX_SIZE, meaning that the list contains the
	//maximum amounts of items possible.

	void destroyList();
	//Precondition:  None
	//Postcondition:  Clears list and resets the size to 0.

	void insert(const pet&) throw(ListException);
	//Precondition:  The pet to be inserted is passed as an argument.
	//Postcondition:  An exception occurs if the list is full or
	//the put is a duplicate.  If no errors arise, the pet is inserted
	//in the proper place after it is compared to other existing elements
	//within the list.
	
	void list::retrieve(pet & p) const throw(ListException);
	//Precondition:  Intakes pet species and name.
	//Postcondition:  Sets p equal to the item found in the list, if any.

	void list::remove(pet & p);
	//Precondition: Intakes a pet's species and name.
	//Postcondition: Removes a pet through left shift logic.


private:
	//Below are instances of the list class, but pet petList is 
	//an instance of the pet class.
	pet petList[MAX_SIZE];
	int size;
};
