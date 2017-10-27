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
	size = 0;
}//end constructor

bool list::isEmpty() const
//Precondition:  None
//Postcondition: Returns boolean value to determine if size is equivalent
//to 0, indicating that there are no items within the list.
{
	return bool(size == 0);
}//end function

bool list::isFull() const
//Precondition: None
//Postcondition: Returns boolean value to determine if size is equivalent
//to the maximum size.
{
	return bool(size == MAX_SIZE);
}//end function

void list::destroyList()
//Precondition:  None
//Postcondition: Clears the list and resets the size to 0.
{
	size = 0;
	//By assigning 0 to size, the amount of items stored in the list
	//is reduced to zero.
}//end function

ostream& operator<<(ostream& out, const list& l)
//Precondition: l is a constant of type list, while out is lefthand operand. 
//Postcondition: Outputs a list of pets by referring to the list class's
//petList, which then enters the pet class's overloaded output and displays
//the name, species, and price of every pet in the list.
{
	if(!l.isEmpty()){
		l.petList[0].displayHdg();  
		//Above not needed for vertical display.
		for(int i = 0; i < l.size; i++){
			out << l.petList[i] << endl;
		}//end for
	}//end if
	
	return out;		
}//end function

void list::insert(const pet& p) throw (ListException)
//Precondition:  The pet to be inserted is passed as an argument.
//Postcondition:  An exception occurs if the list is full or
//the put is a duplicate.  If no errors arise, the pet is inserted
//in the proper place after it is compared to other existing elements
//within the list.
{
	//Check if list is full.
	if(size >= MAX_SIZE) 
		throw ListException("List is full");
	//Find insert location.
	int i = 0;
	while(i < size && petList[i] < p)
		i++;
	//Check for duplicate
	if(i < size && petList[i] == p)
		throw ListException("Duplicate pet.");
	else{ //Insert pet
		//Right shift logic
		
		//Temporary storage variable
		pet j = petList[i];
		for(int pos = size; pos > i; --pos){
			//petList[pos+1] = petList[pos];
			petList[pos+1] = j;
			//cout << j;
		}
		petList[i] = p;
		size++;
	}
}

void list::retrieve(pet & p) const throw(ListException)
//Precondition:  Intakes pet species and name.
//Postcondition:  Sets p equal to the item found in the list, if any.
{
	//Locate pet
	int i = 0;
	while(i < size  && petList[i] < p)
		i++;
	if(i < size &&petList[i] == p)
		p = petList[i];
	else //Pet not found
		throw ListException("Pet not found");
}

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
			petList[i] = petList[i+1];
		}
		size--;
	}
	else //Pet not found
		throw ListException("Pet not found.");
}
