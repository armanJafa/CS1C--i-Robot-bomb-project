/**********************************************************
 * AUTHOR 		 : Austin, Kevin, Arman, Augusto
 * STUDENT ID 	 : 364965
 * Project #2    : Project #2
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 5/13/15
 **********************************************************/

#include "BombClass.h"
#include "KeyCustomer.h"

//default constructor
BombClass::BombClass()
{

}

//creating the member list using vectors
void BombClass::CreateMemberList(ifstream &infile)
{

	Customer * tempList;       // templist to pass into vector member
							   // function
	KeyCustomer * tempKeyList; // temp Object to pass into vector method

	//all temp strings to pass into overloaded constructor
	string tempCompanyName;
	string tempStreetAddress;
	string tempStateAddress;
	string tempCustomerRating;
	string tempField;

	infile.open("Customers.txt");

	//will run through the whole file
	while (infile.good())
	{
		//read in data
		getline(infile, tempCompanyName);
		getline(infile, tempStreetAddress);
		getline(infile, tempStateAddress);
		getline(infile, tempCustomerRating);
		getline(infile, tempField);

		if (tempField == "key")
		{
			//overloaded constructor for key Customers
			tempKeyList = new KeyCustomer(tempCompanyName,
					tempStreetAddress,tempStateAddress,
					tempCustomerRating, tempField);

			//push object on the vector
			list.push_back(tempKeyList);

		}
		else
		{
			//overloaded constructor for regular customers
			tempList = new Customer(tempCompanyName, tempStreetAddress,
					tempStateAddress, tempCustomerRating, tempField);

			//push object on the vector
			list.push_back(tempList);

		}
	}


}

// main menu for users
int BombClass::CustomerMenu()
{
	int tempChoice = -1; // choice by user input

	//OUTPUT - the menu is diplsayed in main program
	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');
	cout << setw(58) << "|  I-ROBOT MENU" << '|' << endl;
	cout << setw(58) << '|' << '|' << endl;
	cout << setw(58) << "| 0  - EXIT" << '|' << endl;
	cout << setw(58) << "| 1  - VIEW PAMPHLET" << '|' << endl;
	cout << setw(58) << "| 2  - VIEW TESTIMONIALS" << '|' << endl;
	cout << setw(58) << "| 3  - ADD TESTIMONIALS " << '|' << endl;
	cout << setw(58) << "| 4  - REQUEST A PAMPHLET " << '|' << endl;
	cout << setw(58) << "| 5  - ORDER ROBOTS" << '|' << endl;
	cout << setw(58) << "| 6  - Administrator Options" << '|' << endl;
	cout << setw(58) << "| 7  - VIEW HELP PAGE" << '|' << endl;
	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');

	//calls get and check, which uses try and catch statements
	tempChoice = GetAndCheckInt(0, 7);
	return tempChoice;

}

//displays the pamphlet from file
void BombClass::DisplayPamphlet()
{
	ifstream infile;   //file to read
	string readString; //string to output read characters

	infile.open("bomb.txt");

	//reads the whole file
	while (infile.good())
	{
		getline(infile, readString);
		cout << readString;
		cout << endl;

	}
	infile.close();
}


//displays the objects using iterator
void BombClass::DisplayMemberList()
{
	cout << "\n\nINFORMATION: \n\n";

	//iterator to output objects data
	vector<Customer*>::iterator index;

	//using methods for loop initalizations
	for (index = list.begin(); index != list.end(); index++)
	{
		//will call virtual function to print
		(*index)->Print();
		cout << endl;
	}
}

//Displays a help menu for the user.
void BombClass::DisplayHelpPage()
{
	ifstream infile;   //file to read
	string readString; //string to output read characters

	infile.open("Help.txt");

	//reads the whole file
	while (infile.good())
	{
		getline(infile, readString);
		cout << readString;
		cout << endl;

	}
	infile.close();
}

/*************************************************************************
 *
 * FUNCTION GetAndCheckInt
 *_________________________________________________________________________
 * This function will check for wrong input entered by the user, only
 * number range passed in should be correct input.
 *_________________________________________________________________________
 * Pre-Conditions
 * 	must have two values as parameters
 *
 * Post-Conditions
 * 	This function will return the pick to main. if not valid, will return
 * 	a -1.
 ************************************************************************/
int BombClass::GetAndCheckInt(int int1, //IN -  lowest allowable parameter
										//      for correct values that
									    //      need to be error checked.
							 int int2) 	//IN -  highest allowable
										//      parameter for correct
										//      values that need to be
										//      error checked.
{

	//default class for throws
	class CharEnter
	{
	};

	//default class for throws
	class WrongInt
	{
	};

	ostringstream buffer; // CALC - used for spacing purposes
	bool inputOk; // CALC - error checking bool
	int pick; // OUT  - will output a correct number

	//OUT - error checking command
	pick = 0;
	inputOk = false;

	try
	{
		cout << "choice: ";

		// if the number is a character
		if (!(cin >> pick))
		{
			throw CharEnter();
		} else
		{
			// this sets bool to true
			inputOk = (pick >= int1 && pick < int2 + 1);

			// if the number is not a valid entry
			if (!inputOk)
			{
				throw WrongInt();
			}

		}

	}
	//catch if a char entered
	catch (CharEnter&)
	{

		cout << endl;
		cout << "**** Please input a NUMBER between "
			 << int1 << " and " << int2 << "       ****";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << endl;
		pick = GetAndCheckInt(int1, int2);

	}
	//catches if a wrong int is entered
	catch (WrongInt&)
	{
		//OUTPUT
		cout << left;
		cout << endl;
		buffer << "**** The number " << pick;
		cout << buffer.str() << setw(49 - buffer.str().length());
		//cout << buffer.width();
		cout << left << " is not a valid entry" << "****";
		cout << endl;
		cout << "**** Please input a NUMBER between ";
		cout << int1 << " and " << setw(6) << left << int2 << "  ****";
		cout << endl << endl;
		buffer.str("");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		pick = GetAndCheckInt(int1, int2);

	}

	// RETURN STATEMENT
	return pick;

}

//menu for admins
int BombClass::AdminMenu()
{

	int tempChoice = -1; // choice by user input

	//OUTPUT - the menu is diplsayed in main program
	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');
	cout << setw(58) << "|  I-ROBOT MENU ADMIN" << '|' << endl;
	cout << setw(58) << '|' << '|' << endl;
	cout << setw(58) << "| 0  - EXIT" << '|' << endl;
	cout << setw(58) << "| 1  - VIEW LIST" << '|' << endl;
	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');

	tempChoice = GetAndCheckInt(0, 1);
	return tempChoice;

}

//administration page
//will run swtich statement of options
void BombClass::AdministrationPage()
{

	int choice= 0;
	do
	{
		//calls admin menu
		//only able to view list at the moment
		choice = AdminMenu();

		if (choice != EXIT)
		{
			switch (choice)
			{
			case VIEW_LIST:

				//calls display members
				DisplayMemberList();
				break;

			}
		}

	} while (choice != EXIT);

}

bool BombClass:: EnterAdminPassword()
{

	int login = 0;
	bool RightPassword = false;

	cout << "Enter Password(ex:0000)\n";
	login = GetAndCheckInt(1000, 9999);

	if(login == 1234)
	{
		RightPassword = true;
	}
	else
	{
		cout << "\nIncorrect Password!\n\n";
	}

	return RightPassword;

}
