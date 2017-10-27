//Filename:  list.h
//Author:  Esquire At Large
//Date written:  February 28th, 2008
//Class description:  Contains function declarations for list containing
//pets.

#pragma once
#include "ListException.h"
#include "pet.h"
#include <iostream>
using namespace std;


class list{

	friend ostream& operator<<(ostream&, const list&);
	//Precondition:  Intakes an instance of list.
	//Postcondition:  Outputs the items of the list in sorted order.



public:
	list();
	//Constructor
	//Precondition: None
	//Postcondition: Sets size to zero.
	
	list(const list& clist);
	//Copy constructor
	//Precondition:  Intakes an instance of list.
	//Postcondition:  Calls the copylist function.

	~list();
	//Destructor
	//Precondition:  Destructor to deallocate list's space in memory.
	//Postcondition:  Calls function to destroy the list.

	bool isEmpty() const;
	//Precondition: None
	//Postcondition: Returns boolean value to determine if head is
	//equivalent to NULL, meaning that the list contains no items.
	
	void destroyList();
	//Precondition:  None
	//Postcondition:  Clears list and deletes each node.
	void copyList(const list& l);
	//Precondition:  Intakes original list.
	//Postcondition:  Returns the copy of the list.

	void insert(const pet& p) throw(ListException);
	//Precondition:  The pet to be inserted is passed as an argument.
	//Postcondition:  An exception occurs if the list is full or
	//the put is a duplicate.  If no errors arise, the pet is inserted
	//in the proper place after it is compared to other existing elements
	//within the list.
	
	void retrieve(pet & p) const throw(ListException);
	//Precondition:  Intakes pet species and name.
	//Postcondition:  Sets p equal to the item found in the list, if any.

	void remove(pet & p) throw(ListException);
	//Precondition: Intakes a pet's species and name.
	//Postcondition: Removes a pet through left shift logic.

	const list& operator=(const list& rhs);
	//Precondition:  Intakes an instance of list.
	//Postcondition:  Makes a deep copy of a list by calling
	//copylist function.


private:
	//Below are instances of the list class, but pet p  is 
	//an instance of the pet class.
	struct node{
		pet p; 
		node* next; 
	};
	node* head;
};
