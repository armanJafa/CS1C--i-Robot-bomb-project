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
#include "Customer.h"
#include <algorithm>
//default constructor
BombClass::BombClass()
{

	NeedToAddMembers = false;

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
	string tempTestimonial;
	string recievedPamphlet;

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
		getline(infile, recievedPamphlet);
		getline(infile, tempTestimonial);

		//cout << recievedPamphlet << endl;

		if (tempField == "key")
		{
			//overloaded constructor for key Customers
			tempKeyList = new KeyCustomer(tempCompanyName, tempStreetAddress,
					tempStateAddress, tempCustomerRating, tempField,
					tempTestimonial, recievedPamphlet);

			//push object on the vector
			list.push_back(tempKeyList);

		} else
		{
			//overloaded constructor for regular customers
			tempList = new Customer(tempCompanyName, tempStreetAddress,
					tempStateAddress, tempCustomerRating, tempField,
					tempTestimonial, recievedPamphlet);

			//push object on the vector
			list.push_back(tempList);

		}
	}
	infile.close();
	infile.clear();
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
	infile.clear();
}

//displays the objects using iterator
void BombClass::DisplayMemberList()
{
	cout << "\n\nINFORMATION: \n\n";

	cout << left;

	/**
	 * << setw(25) << "STREET ADDRESS" << setw(20)
	 << "STATE ADDRESS" << setw(20) << "RATING" << setw(20) << "RECIEVED PAMPHLET"
	 << setw(20) << "KEY" << setw(20) << endl;
	 */

	cout << setw(25) << "COMPANY" << setw(26) << "STREET ADDRESS" << setw(24)
			<< "STATE ADDRESS" << setw(26) << "RATING" << setw(24)
			<< "RECIEVED PAMPHLET" << setw(25) << "KEY" << endl;

	cout << setfill('-') << '-';

	cout << setw(23) << '-' << " " << setw(24) << '-' << "  " << setw(23) << '-'
			<< " " << setw(24) << '-' << "  " << setw(23) << '-' << " "
			<< setw(15) << '-' << "  " << endl;

	cout << setfill(' ');

	//iterator to output objects data
	vector<Customer*>::iterator index;

	sort(list.begin(), list.end());

	//using methods for loop initalizations
	for (index = list.begin(); index != list.end(); index++)
	{
		//will call virtual function to print
		(*index)->Print();
		cout << endl;
	}

	cout << endl << endl;
}

void BombClass::DisplayKeyMemberList()
{
	cout << "\n\nINFORMATION: \n\n";

	cout << left;

	/**
	 * << setw(25) << "STREET ADDRESS" << setw(20)
	 << "STATE ADDRESS" << setw(20) << "RATING" << setw(20) << "RECIEVED PAMPHLET"
	 << setw(20) << "KEY" << setw(20) << endl;
	 */

	cout << setw(25) << "COMPANY" << setw(26) << "STREET ADDRESS" << setw(24)
			<< "STATE ADDRESS" << setw(26) << "RATING" << setw(24)
			<< "RECIEVED PAMPHLET" << setw(25) << "KEY" << endl;

	cout << setfill('-') << '-';

	cout << setw(23) << '-' << " " << setw(24) << '-' << "  " << setw(23) << '-'
			<< " " << setw(24) << '-' << "  " << setw(23) << '-' << " "
			<< setw(15) << '-' << "  " << endl;

	cout << setfill(' ');

	//iterator to output objects data
	vector<Customer*>::iterator index;

	sort(list.begin(), list.end());

	//using methods for loop initalizations
	for (index = list.begin(); index != list.end(); index++)
	{

		(*index)->PrintKeyCustomer();
		cout << endl;
	}

	cout << endl << endl;

}

void BombClass::RequestAPamphlet(ofstream &outfile)
{

	char data;
	int searchReturn = -1;
	string tempCompanyName;
	string tempStreetAddress;
	string tempStateAddress;
	string tempTestimonial;

	outfile.open("CustomersToAdd.txt", std::fstream::app);

	cin.ignore(1000, '\n');
	do
	{
		cout << "\nAre you already a customer on our list?: ";
		data = GetAndCheck('Y', 'N');
	} while (data == 1);

	if (data == 'N')
	{
		//cin.ignore(1000, '\n');
		cout << "\nEnter your data to revieve a pamphlet :\n\n";

		cout << "Company Name: ";
		getline(cin, tempCompanyName);
		cout << endl;

		cout << "Company Street Address: ";
		getline(cin, tempStreetAddress);
		cout << endl;

		cout << "Company State Address: ";
		getline(cin, tempStateAddress);
		cout << endl;

		tempTestimonial = "none";

		outfile << tempCompanyName << endl;
		outfile << tempStreetAddress << endl;
		outfile << tempStateAddress << endl;
		outfile << tempTestimonial << endl;

		cout << "Thank you for requesting a pamphlet!" << endl
				<< "A member of our administrative team will approve your"
						" information in 1-3 buisness days!\n\n";

		NeedToAddMembers = true;
	} else
	{

		cout << endl;
		cout << "Company Name: ";
		getline(cin, tempCompanyName);
		cout << endl;
		searchReturn = SearchCompanyName(tempCompanyName);
		if (searchReturn != -1)
		{
			cout << "Okay, " << tempCompanyName
					<< " sending a pamphlet\n\n";

			list[searchReturn]->SetRevcievedPamphlet("Yes");



		} else
		{
			cout << "\n\nCompany is not in our system!\n\n";
		}

	}

	outfile.close();
	outfile.clear();
}

void BombClass::ViewTestimonials()
{

	//iterator to output objects data
	vector<Customer*>::iterator index;

	//using methods for loop initalizations
	cout << "\n\nTestimonials from our clients:\n\n";
	for (index = list.begin(); index != list.end(); index++)
	{
		if ((*index)->GetTestimonial() != "none")
		{
			cout << (*index)->GetCompanyName() << ": ";
			cout << (*index)->GetTestimonial();
			cout << endl << endl;
		}

	}

}

void BombClass::WriteTestimonials()
{

	string searchName;
	string tempTestimonial;
	int index = 0;

	cin.ignore(1000, '\n');
	cout << "\nEnter your company name: ";
	getline(cin, searchName);

	index = SearchCompanyName(searchName);

	if (index != -1)
	{
		cout << "Okay " << list[index]->GetCompanyName()
				<< " enter your testimonial:";
		getline(cin, tempTestimonial);

		list[index]->SetTestimonial(tempTestimonial);

	} else
	{
		cout << "\nYour company does not exist..\n";
	}

	cout << endl;
}

int BombClass::SearchCompanyName(string searchName)
{

	//iterator to output objects data
	unsigned int foundIndex = 0;

	//using methods for loop initalizations
	cout << "searching for " << searchName << "." << endl << endl;

	while (foundIndex <= list.size() - 1)
	{
		if (list[foundIndex]->GetCompanyName() == searchName)
		{

			return foundIndex;

		}

		foundIndex++;
	}

	return -1;
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
	infile.clear();
}

void BombClass::SaveBetweenExecutions()
{
	ofstream outputfile;
	outputfile.open("Customers.txt");

	//iterator to output objects data
	vector<Customer*>::iterator index;

	//using methods for loop initalizations
	for (index = list.begin(); index != list.end(); index++)
	{
		//will call virtual function to print
		outputfile << (*index)->GetCompanyName();
		outputfile << endl;
		outputfile << (*index)->GetStreetAddress();
		outputfile << endl;
		outputfile << (*index)->GetStateAddress();
		outputfile << endl;
		outputfile << (*index)->GetCustomerRating();
		outputfile << endl;
		outputfile << (*index)->GetField();
		outputfile << endl;
		outputfile << (*index)->GetPamphlet();
		outputfile << endl;
		outputfile << (*index)->GetTestimonial();

		if (index != list.end() - 1)
			outputfile << endl;
	}

	outputfile.close();
	outputfile.clear();

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
		cout << "**** Please input a NUMBER between " << int1 << " and " << int2
				<< "       ****";
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

/*************************************************************************
 *
 * FUNCTION GetAndCheck
 *_________________________________________________________________________
 * This function will check for wrong input entered by the user for
 * character values
 *_________________________________________________________________________
 * Pre-Conditions
 * 	must be called in main
 *
 * Post-Conditions
 * 	This function will return the pick to main. if not valid, will return
 * 	loop till the value is valid
 *************************************************************************/
char BombClass::GetAndCheck(char val1, char val2)
{
	char input;   // IN   - user yes or no for initializing
	bool inputOk; // CALC - calcs reather or not value is appropriate

	//OUT
	inputOk = false;
	cin >> input;
	//uppercase
	input = toupper(input);

	//correct values
	inputOk = (input == val1 || input == val2);

	// if not correct
	if (!inputOk)
	{
		//out
		cout << endl;
		cout << " **** " << input << " is an invalid "
				"entry ****\n";
		cout << " **** Please input " << val1 << " or " << val2 << setw(8)
				<< right << " ****\n";
		cin.clear();

		input = 1;
		cout << endl;

	}
	cin.ignore(1000, '\n');
	//end of error check do-while

	return input;

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
	cout << setw(58) << "| 2  - ADD MEMBER" << '|' << endl;
	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');

	tempChoice = GetAndCheckInt(0, 2);
	return tempChoice;

}

//administration page
//will run swtich statement of options
void BombClass::AdministrationPage()
{

	int choice = 0;
	do
	{

		if (NeedToAddMembers)
		{
			cout << "\n***NEED TO ADD MEMBERS TO SEND PAMPHLET"
					"(HIT OPTION 2)!***\n\n";
		}

		//calls admin menu
		//only able to view list at the moment
		choice = AdminMenu();

		if (choice != EXIT)
		{
			switch (choice) {
			case VIEW_LIST:

				//calls display members
				DisplayMemberList();
				break;

			case ADD_MEMBERS:
				AddMembers();
				break;

			}
		}

	} while (choice != EXIT);

}

void BombClass::AddMembers()
{

	Customer * tempList;       // templist to pass into vector member
							   // function
	KeyCustomer * tempKeyList; // temp Object to pass into vector method

	string tempCompanyName;  //have
	string tempStreetAddress;  //have
	string tempStateAddress; //have
	string tempCustomerRating; //overloaded
	string tempField;          //overloaded
	string tempTestimonial;    //have
	string tempRecievedPamphlet;
	ifstream infile;
	char input;

	infile.open("CustomersToAdd.txt");

	cout << "Add new members\n\n";
	if (NeedToAddMembers)
	{
		cout << "\n\nHere is the new member list:\n\n";
		DisplayNewMembers();
		cout << endl << endl;

		while (infile.good())
		{
			getline(infile, tempCompanyName);
			if (tempCompanyName.length() > 0)
			{

				do
				{
					cout << "Is " << tempCompanyName << " a new KEY customer?: ";
					input = GetAndCheck('Y', 'N');
				} while (input == 1);

				getline(infile, tempStreetAddress);
				getline(infile, tempStateAddress);
				getline(infile, tempTestimonial);
				tempRecievedPamphlet = "Yes";

				if (input == 'Y')
				{
					//cin.ignore(1000, '\n');
					cout << "\n\nEnter a customer rating"
							"(Interested <very/not so much>: ";
					getline(cin, tempCustomerRating);

					tempField = "key";

					tempKeyList = new KeyCustomer(tempCompanyName,
							tempStreetAddress, tempStateAddress,
							tempCustomerRating, tempField, tempTestimonial,
							tempRecievedPamphlet);

					list.push_back(tempKeyList);
				} else
				{
					tempList = new Customer(tempCompanyName, tempStreetAddress,
							tempStateAddress, tempTestimonial);
					cin >> *tempList;
					list.push_back(tempList);

					//setting other fields for admin type only
				}
			}
		}

		infile.close();
		infile.clear();

		remove("CustomersToAdd.txt");

		/****
		 remove("CustomersToAdd.txt");
		 if( remove( "CustomersToAdd.txt" ) != 0 )
		 perror( "Error deleting file" );
		 else
		 puts("File successfully deleted");

		 ***/
		NeedToAddMembers = false;

	} else
	{
		cout << "\nNo new customers requested a pamphlet!\n\n";
	}

}

void BombClass::DisplayNewMembers()
{
	ifstream infile;   //file to read
	string readCompany;
	string readStreetAdd;
	string readStateAdd;
	string tempTestimonial;

	cout << setw(25) << "COMPANY" << setw(26) << "STREET ADDRESS" << setw(24)
				<< "STATE ADDRESS" << setw(20) << "WRITTEN TESTIMONIAL?" << endl;
	cout << setfill('-') << '-';

	cout << setw(23) << '-' << " " << setw(24) << '-' << "  " << setw(23) << '-'
			<< " " <<  setw(20) << '-' << " " <<  endl;

	cout << setfill(' ');

	infile.open("CustomersToAdd.txt");

	//reads the whole file
	while (infile.good())
	{
		getline(infile, readCompany);

		if(readCompany.length() > 0)
		{
		getline(infile, readStreetAdd);
		getline(infile, readStateAdd);
		getline(infile, tempTestimonial);
		cout << setw(25) << readCompany << setw(26) << readStreetAdd << setw(24)
			 << readStateAdd << setw(20) << tempTestimonial << endl;
		}


	}
	infile.close();
	infile.clear();

}

bool BombClass::EnterAdminPassword()
{

	int login = 0;
	bool RightPassword = false;

	cout << "Enter Password(ex:0000)\n";
	login = GetAndCheckInt(1000, 9999);

	if (login == 1234)
	{
		RightPassword = true;
	} else
	{
		cout << "\nIncorrect Password!\n\n";
	}

	return RightPassword;

}
