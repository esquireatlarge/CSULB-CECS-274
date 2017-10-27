//Filename:  proj4.cpp
//Author:  Esquire At Large
//Date written: April 10th, 2008
//Program Description: Converts an infix expression to its
//equivalent postfix expression.

#include <iostream>
#include <string>

int getValidInt(char * prompt);
//Precondition:  prompt is the prompt for the integer.
//Postcondition: Displays the validity of the integer
//input by the user.

void progIntro();
//Precondition: None
//Postcondition:  Displays the purpose of the program
//to user.

int getMenuOption();
//Precondition:  Receives menu option selected by the user.
//Postcondition:  Performs validity checks on option then
//returns it.

int main(){
	int menuOption;

	progIntro() //Display purpose of the program.

	do{
		menuOption = getMenuOption();
		switch(menuOption){
i			case 1:
				//Convert operation
				break;
			case 2:
				//Exit
				cout << "Program terminating, have a good day."
					<< endl;
				break;
		}
	}while(menuOption != 2);
}

int getValidInt(char* prompt)
//Pre-condition: prompt is the prompt for the integer.
//Post-condition: Displays the validity of the integer
//input by the user.
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

void progIntro(){
//Precondition: None
//Postcondition:  Displays the purpose of the program
//to user.
	cout << "This program converts an infix expression to its"
		<< "\nequivalent postfix expression." << endl;
}

int getMenuOption(){
//Precondition:  Receives menu option selected by the user.
//Postcondition:  Performs validity checks on option then
//returns it.
        int menuOption;
        cout << endl
                << "1: Convert an infix expression to postfix.\n"
                << "2: Exit program.\n" << endl;
        menuOption = getValidInt("Enter a menu option from 1 to 2: ");
        return menuOption;
}

