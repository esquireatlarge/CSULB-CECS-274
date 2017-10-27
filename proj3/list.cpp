//Filename: list.cpp
//Author:  Esquire At Large
//Date written: February 28th, 2008
//Class description:  Contains function definitions for list.h file.
//Function definitions to determine if list is empty or full, and if the 
//list needs to be destroyed or updated.

#include "list.h"

list::list()
//Precondition:  None
//Postcondition: Sets size to zero as default.
{
	head = NULL;
}//end constructor

bool list::isEmpty() const
//Precondition:  None
//Postcondition: Returns boolean value to determine if head is equivalent
//to NULL, indicating that there are no nodes in the list.
{
	return bool(head==NULL);
}//end function

bool list::isFull() const
//Precondition: None
//Postcondition: Returns boolean value to determine if size is equivalent
//to the maximum size.
{
//	return bool(size == MAX_SIZE);
}//end function

void list::destroyList()
//Precondition:  None
//Postcondition: Clears the list and destroys the nodes.
{
	node* cur = head;

	//Delete list
	while(cur!=NULL){
		//Head points to node after one cur points to
		head = head->next;
		delete cur;
		cur = head;
	}
		


}//end function

ostream& operator<<(ostream& out, const list& l)
//Precondition: l is a constant of type list, while out is lefthand operand. 
//Postcondition: Outputs a list of pets by referring to the list class's
//petList, which then enters the pet class's overloaded output and displays
//the name, species, and price of every pet in the list.
{	
	list::node* cur = l.head;

	//While not and end of list
	while(cur->next != NULL){
		/*code for outputting node items*/
		out << cur->p;
		cur = cur->next;	
	}
	return out;		
}//end function

void list::insert(const pet& p) throw (ListException)
//Precondition:  The pet to be inserted is passed as an argument.
//Postcondition:  An exception occurs if the list is full or
//the put is a duplicate.  If no errors arise, the pet is inserted
//in the proper place after it is compared to other existing elements
//within the list.
{
	node* cur = head, *prev = NULL;	
	//Locate position in list for insert.
	while(cur != NULL && cur->p < p){
		prev = cur;
		cur = cur->next;
	} 
	//Check for duplicate
	while(cur!=NULL && cur->p == p) 
		throw ListException("Duplicate pet.");
	//Allocate space
	node* newPtr = new node;
	if(newPtr == NULL)
		throw ListException("Cannot allocate memory.");
	//Insert node
	newPtr->p=p;
	//Head insert
	if(cur==head){
		newPtr->next = head;
		head = newPtr;
	}
	else{ //Not a head insert
		newPtr->next=prev->next;
		prev->next=newPtr;
	}
}
void list::retrieve(pet & p) const throw(ListException)
//Precondition:  Intakes pet species and name.
//Postcondition:  Sets p equal to the item found in the list, if any.
{
	node* cur = head;
	//Locate pet
	while(cur != NULL && cur->p < p){
		cur = cur->next;
	}
	if(cur!= NULL && cur->p == p)
		p = cur->p;
	else //Not found
		throw ListException("Pet not found.");
}

/*
void list::remove(pet & p)
//Precondition: Intakes a pet's species and name.
//Postcondition: Removes a pet through left shift logic.
{
	int i = 0;
	//Locate pet
	while(i < size && petList[i] < p)
		i++;
	if(i < size && petList[i] == p){  //Pet found.
		//Left shift logic.
		for(int pos = i; pos < size-1; pos++){
			petList[pos] = petList[pos+1];
		}
		size--;
	}
	else //Pet not found
		throw ListException("Pet not found.");
}
*/
