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

/*************************************************************************
 *
 * FUNCTION BombClass
 *________________________________________________________________________
 * This function will set all values to initial values
 *________________________________________________________________________
 ************************************************************************/
BombClass::BombClass()
{

	//set values
	NeedToAddMembers = false;

}

/*************************************************************************
 *
 * FUNCTION CreateMemberList
 *________________________________________________________________________
 * This function creates the member list
 *________________________________________________________________________
 ************************************************************************/
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
			tempKeyList = new KeyCustomer(tempCompanyName,
					tempStreetAddress,tempStateAddress,
					tempCustomerRating, tempField,tempTestimonial,
					recievedPamphlet);

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

/*************************************************************************
 *
 * FUNCTION CustomerMenu
 *________________________________________________________________________
 * This function displays main menu for users
 *________________________________________________________________________
 ************************************************************************/
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

/*************************************************************************
 *
 * FUNCTION DisplayPamphlet
 *________________________________________________________________________
 * This function displays the pamphlet
 *________________________________________________________________________
 ************************************************************************/
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

/*************************************************************************
 *
 * FUNCTION DisplayMemberList
 *________________________________________________________________________
 * This function displays the member list
 *________________________________________________________________________
 ************************************************************************/
void BombClass::DisplayMemberList()
{
	cout << "\n\nINFORMATION: \n\n";

	Customer * tempItem = NULL;  // temp item for sort

	cout << left;

	//bubble sort
	for (unsigned int i = 0; i < list.size(); i++)
	{
		for (unsigned int j = 0; j < list.size(); j++)
		{
			if (list[i]->GetCompanyName() < list[j]->GetCompanyName())
			{
				tempItem = list[i];
				list[i] = list[j];
				list[j] = tempItem;
			}
		}
	}

	//outputs the header
	cout << setw(25) << "COMPANY" << setw(26) << "STREET ADDRESS"
			<< setw(24) << "STATE ADDRESS" << setw(26)
			<< "RATING" << setw(24)
			<< "RECIEVED PAMPHLET" << setw(25) << "KEY" << endl;

	cout << setfill('-') << '-';

	cout << setw(23) << '-' << " " << setw(24) << '-' << "  " << setw(23)
			<< '-'<< " " << setw(24) << '-' << "  " << setw(23) << '-'
			<< " " << setw(15) << '-' << "  " << endl;

	cout << setfill(' ');

	//iterator to output objects data
	vector<Customer*>::iterator index;

	//using methods for loop initalizations
	for (index = list.begin(); index != list.end(); index++)
	{
		//will call virtual function to print
		(*index)->Print();
		cout << endl;
	}

	cout << endl << endl;
}

/*************************************************************************
 *
 * FUNCTION DisplayKeyMemberList
 *________________________________________________________________________
 * This function displays the key members
 *________________________________________________________________________
 ************************************************************************/
void BombClass::DisplayKeyMemberList()
{
	cout << "\n\nINFORMATION: \n\n";

		Customer * tempItem = NULL;  // temp item for sort

		cout << left;

		//bubble sort
		for (unsigned int i = 0; i < list.size(); i++)
		{
			for (unsigned int j = 0; j < list.size(); j++)
			{
				if (list[i]->GetCompanyName() < list[j]->GetCompanyName())
				{
					tempItem = list[i];
					list[i] = list[j];
					list[j] = tempItem;
				}
			}
		}

	cout << left;

	//output headers
	cout << setw(25) << "COMPANY" << setw(26) << "STREET ADDRESS"
		 << setw(24)<< "STATE ADDRESS" << setw(26) << "RATING"
		 << setw(24)<< "RECIEVED PAMPHLET" << setw(25) << "KEY" << endl;

	cout << setfill('-') << '-';

	cout << setw(23) << '-' << " " << setw(24) << '-' << "  " << setw(23)
		 << '-' << " " << setw(24) << '-' << "  " << setw(23) << '-' << " "
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

/*************************************************************************
 *
 * FUNCTION RequestAPamphlet
 *________________________________________________________________________
 * This function requests a pamphlet
 *________________________________________________________________________
 ************************************************************************/
void BombClass::RequestAPamphlet(ofstream &outfile) // output file
{

	char data;                //data entered
	int searchReturn = -1;    // search companies
	string tempCompanyName;   // temp name
	string tempStreetAddress; // street address
	string tempStateAddress;  // state address
	string tempTestimonial;   // testimonials

	//appends the file
	outfile.open("CustomersToAdd.txt", std::fstream::app);

	//adds data to the outpf file
	cin.ignore(1000, '\n');
	do
	{
		//output
		cout << "\nAre you already a customer on our list?: ";
		data = GetAndCheck('Y', 'N');
	} while (data == 1);

	if (data == 'N')
	{
		//output
		cout << "\nEnter your data to revieve a pamphlet :\n\n";

		cout << "Company Name: ";
		getline(cin, tempCompanyName);
		cout << endl;

		//output
		cout << "Company Street Address: ";
		getline(cin, tempStreetAddress);
		cout << endl;

		cout << "Company State Address: ";
		getline(cin, tempStateAddress);
		cout << endl;

		tempTestimonial = "none";

		//output
		outfile << tempCompanyName << endl;
		outfile << tempStreetAddress << endl;
		outfile << tempStateAddress << endl;
		outfile << tempTestimonial << endl;

		//output
		cout << "Thank you for requesting a pamphlet!" << endl
				<< "A member of our administrative team will approve your"
						" information in 1-3 buisness days!\n\n";

		NeedToAddMembers = true;
	}
	else
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

	//closes and clears the files
	outfile.close();
	outfile.clear();
}

/*************************************************************************
 *
 * FUNCTION ViewTestimonials
 *________________________________________________________________________
 * This function views testimonials
 *________________________________________________________________________
 ************************************************************************/
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

/*************************************************************************
 *
 * FUNCTION WriteTestimonials
 *________________________________________________________________________
 * This function allows a customer to write testimonials
 *________________________________________________________________________
 ************************************************************************/
void BombClass::WriteTestimonials()
{

	string searchName;
	string tempTestimonial;
	int index = 0;

	cin.ignore(1000, '\n');
	cout << "\nEnter your company name: ";
	getline(cin, searchName);

	//finds index of company
	index = SearchCompanyName(searchName);

	//will add testimonial
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

/*************************************************************************
 *
 * FUNCTION SearchCompanyName
 *________________________________________________________________________
 * This function allows a company to be searched for
 *________________________________________________________________________
 ************************************************************************/
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

/*************************************************************************
 *
 * FUNCTION DisplayHelpPage
 *________________________________________________________________________
 * This function allows a company to find help
 *________________________________________________________________________
 ************************************************************************/
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

/*************************************************************************
 *
 * FUNCTION SaveBetweenExecutions
 *________________________________________________________________________
 * This function saves between executions
 *________________________________________________________________________
 ************************************************************************/
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
		cout << "**** Please input a NUMBER between " << int1
			 << " and " << int2 << "       ****";
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
	cout << setw(58) << "| 3  - VIEW KEY MEMBERS" << '|' << endl;
	cout << setw(58) << "| 4  - DELETE MEMBER" << '|' << endl;
	cout << setw(58) << "| 5  - CHANGE MEMBER DATA" << '|' << endl;
	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');

	tempChoice = GetAndCheckInt(0, 5);
	return tempChoice;

}

/*************************************************************************
 *
 * FUNCTION AdministrationPage
 *________________________________________________________________________
 * This function is the main program for the admin
 *________________________________________________________________________
 ************************************************************************/
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
			switch (choice)
			{
			case VIEW_LIST:

				//calls display members
				DisplayMemberList();
				break;

				//calls add members
			case ADD_MEMBERS:
				AddMembers();
				break;

				//calls delete members
			case DELETE_MEMBERS:
				DeleteMembers();
				break;

				//calls change data
			case CHANGE_DATA:
				ChangeData();
				break;

				//calls view key customers
			case VIEW_KEY_LIST:
				DisplayKeyCustomers();
				break;

			}
		}

	} while (choice != EXIT);

}

/*************************************************************************
 *
 * FUNCTION DeleteMembers
 *________________________________________________________________________
 * This function deletes members
 *________________________________________________________________________
 ************************************************************************/
void BombClass::DeleteMembers()
{

	string searchName;  // name to search for
	int index = 0;      // index for item found

	cin.ignore(1000, '\n');

	//input
	cout << "\nEnter the name of the company you wish to delete: ";
	getline(cin, searchName);

	//function call
	index = SearchCompanyName(searchName);

	//deletes company
	if (index != -1)
	{
		cout << "\nThe company " << list[index]->GetCompanyName()
				<< " is deleted...\n\n";
		list.erase(list.begin() + index);

	}
	else
	{
		cout << "\nCompany NOT found!\n\n";
	}

}

/*************************************************************************
 *
 * FUNCTION DeleteMembers
 *________________________________________________________________________
 * This function allows admin to change data
 *________________________________________________________________________
 ************************************************************************/
void BombClass::ChangeData()
{
	string searchName;
	int index = 0;
	string tempCustomerRating; //overloaded
	string tempField;          //overloaded
	string tempStreetAddress;  //have
	string tempStateAddress;   //have


	//output
	cin.ignore(1000, '\n');
	cout << "\nEnter the name of the company you wish to change: ";
	getline(cin, searchName);
	index = SearchCompanyName(searchName);

	if (index != -1)
	{
		//output
		cout << "\nEnter a customer rating"
				"(Interested <very/not so much>: ";
		getline(cin, tempCustomerRating);
		cout << endl;

		//function call
		list[index]->SetCustomerRating(tempCustomerRating);

		cout << "Company Street Address: ";
		getline(cin, tempStreetAddress);
		cout << endl;

		//function call
		cout << "Company State Address: ";
		getline(cin, tempStateAddress);
		cout << endl;

		//function call
		list[index]->SetAddressRating(tempStateAddress, tempStreetAddress);

		if (list[index]->GetField() != "key")
		{

			cout << "\nEnter Field(nice to have? Not so much?): ";
			getline(cin, tempField);

			//function call
			list[index]->SetField(tempField);


		}
		else
		{
			cout << "\n\nThis customer is a key customer.. already\n\n";
		}

	}
	cout << endl;

}

/*************************************************************************
 *
 * FUNCTION AddMembers
 *________________________________________________________________________
 * This function adds members
 *________________________________________________________________________
 ************************************************************************/
void BombClass::AddMembers()
{

	Customer * tempList;       // templist to pass into vector member
							   // function
	KeyCustomer * tempKeyList; // temp Object to pass into vector method

	//all temp data variables

	string tempCompanyName;
	string tempStreetAddress;
	string tempStateAddress;
	string tempCustomerRating;
	string tempField;
	string tempTestimonial;
	string tempRecievedPamphlet;
	ifstream infile;
	char input;

	//opens file
	infile.open("CustomersToAdd.txt");

	cout << "Add new members\n\n";

	//must have data in file
	if (NeedToAddMembers)
	{
		cout << "\n\nHere is the new member list:\n\n";
		DisplayNewMembers();
		cout << endl << endl;

		//will read from the data
		while (infile.good())
		{
			getline(infile, tempCompanyName);
			if (tempCompanyName.length() > 0)
			{

				do
				{
					cout << "Is " << tempCompanyName
							<< " a new KEY customer?: ";
					input = GetAndCheck('Y', 'N');
				} while (input == 1);

				//reads from file
				getline(infile, tempStreetAddress);
				getline(infile, tempStateAddress);
				getline(infile, tempTestimonial);
				tempRecievedPamphlet = "Yes";

				if (input == 'Y')
				{
					cout << "\n\nEnter a customer rating"
							"(Interested <very/not so much>: ";
					getline(cin, tempCustomerRating);

					tempField = "key";

					//creates a new object
					tempKeyList = new KeyCustomer(tempCompanyName,
						tempStreetAddress, tempStateAddress,
						tempCustomerRating, tempField, tempTestimonial,
						tempRecievedPamphlet);

					list.push_back(tempKeyList);
				}
				else
				{
					//creates a new object
					tempList = new Customer(tempCompanyName,
							tempStreetAddress,
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

		NeedToAddMembers = false;

	}
	else
	{
		cout << "\nNo new customers requested a pamphlet!\n\n";
	}

}

/*************************************************************************
 *
 * FUNCTION DisplayNewMembers
 *________________________________________________________________________
 * This function displays new members to be added
 *________________________________________________________________________
 ************************************************************************/
void BombClass::DisplayNewMembers()
{
	ifstream infile;   //file to read
	string readCompany;
	string readStreetAdd;
	string readStateAdd;
	string tempTestimonial;

	cout << setw(25) << "COMPANY" << setw(26)
		 << "STREET ADDRESS" << setw(24)
		 << "STATE ADDRESS" << setw(20) << "WRITTEN TESTIMONIAL?" << endl;
	cout << setfill('-') << '-';

	cout << setw(23) << '-' << " " << setw(24) << '-' << "  "
			<< setw(23) << '-'
			<< " " << setw(20) << '-' << " " << endl;

	cout << setfill(' ');

	infile.open("CustomersToAdd.txt");

	//reads the whole file
	while (infile.good())
	{
		getline(infile, readCompany);

		if (readCompany.length() > 0)
		{
			getline(infile, readStreetAdd);
			getline(infile, readStateAdd);
			getline(infile, tempTestimonial);
			cout << setw(25) << readCompany << setw(26) << readStreetAdd
					<< setw(24) << readStateAdd << setw(20)
					<< tempTestimonial
					<< endl;
		}

	}
	infile.close();
	infile.clear();

}

/*************************************************************************
 *
 * FUNCTION EnterAdminPassword
 *________________________________________________________________________
 * This function allows a password to be entered
 *________________________________________________________________________
 ************************************************************************/
bool BombClass::EnterAdminPassword()
{

	int login = 0;
	bool RightPassword = false;

	cout << "Enter Password(ex:0000)\n";
	login = GetAndCheckInt(1000, 9999);

	//checks to see if the logon is correct
	if (login == 1234)
	{
		RightPassword = true;
	}
	else
	{
		cout << "\nIncorrect Password!\n\n";
	}

	return RightPassword;

}

/*************************************************************************
 *
 * FUNCTION EnterAdminPassword
 *________________________________________________________________________
 * This function allows a password to be entered
 *________________________________________________________________________
 ************************************************************************/
void BombClass::DisplayKeyCustomers()
{
	cout << "\n\nINFORMATION: \n\n";

	cout << left;

	cout << setw(25) << "COMPANY" << setw(26)
		<< "STREET ADDRESS" << setw(24)
		<< "STATE ADDRESS" << setw(26) << "RATING" << setw(24)
		<< "RECIEVED PAMPHLET" << setw(25) << "KEY" << endl;

	cout << setfill('-') << '-';

	cout << setw(23) << '-' << " " << setw(24) << '-'
		 << "  " << setw(23) << '-'
		<< " " << setw(24) << '-' << "  " << setw(23) << '-' << " "
		<< setw(15) << '-' << "  " << endl;

	cout << setfill(' ');

	//iterator to output objects data
	vector<Customer*>::iterator index;

	sort(list.begin(), list.end());

	//using methods for loop initalizations
	for (index = list.begin(); index != list.end(); index++)
	{
		if ((*index)->GetField() == "key")
		{
			//will call virtual function to print
			(*index)->Print();
			cout << endl;
		}
	}

	cout << endl << endl;
}

/*************************************************************************
 *
 * FUNCTION EnterAdminPassword
 *________________________________________________________________________
 * This function views the purchase menu
 *________________________________________________________________________
 ************************************************************************/
int BombClass::PurchaseMenu()
{
	int tempChoice = -1; // choice by user input

	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');
	cout << setw(58) << "|  I-ROBOT PURCHASE MENU" << '|' << endl;
	cout << setw(58) << '|' << '|' << endl;
	cout << setw(58) << "| 0  - EXIT" << '|' << endl;
	cout << setw(58) << "| 1  - BUY BASIC i-Robot" << '|' << endl;
	cout << setw(58) << "| 2  - BUY Bomb Destroyer" << '|' << endl;
	cout << setw(58) << "| 3  - BUY Ultra-Bot" << '|' << endl;
	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');

	tempChoice = GetAndCheckInt(0, 3);
	return tempChoice;
}

/*************************************************************************
 *
 * FUNCTION Purchase
 *________________________________________________________________________
 * This function allows users to purchase items
 *________________________________________________________________________
 ************************************************************************/
void BombClass::Purchase(ofstream &outfile)
{
	//VARIABLE DECLARATIONS
	int choice;        //IN & OUT  - The user's menu selection
	int quantity;      //IN & CALC - The purchase quantity
	char answer;       //IN & OUT  - User's answer to purchase more
	saleNode *newNode; //CALC 	    - A new purchase node
	saleNode *head;    //CALC		- head to the list
	saleNode *tail;    //CALC 		- tail of the list
	saleNode *tempPtr; //CALC		- pointer to traverse the list
	bool exit;         //CALC		- T/F to exit menu

	//VARIABLE INITIALIZATIONS
	choice = 0;
	quantity = 0;
	head = NULL;
	tail = NULL;
	tempPtr = head;
	exit = false;
	answer = 1;

	//PROCESSING - DO-WHILE - Used to output the menu and process the
	//			   purchases. Exits once the user chooses to not add any
	//			   other robots
	do
	{
		//PurchaseMenu - displays the purchases menu
		cout << endl;
		//cin.ignore(1000,'\n');
		choice = PurchaseMenu();

		//PROCESSING - SWITCH - Used to branch out into the different
		//			   robot options
		switch (choice)
		{
		case SALE_EXIT:	//Exits the switch
			exit = true;
			break;
		case BASIC:	//Purchases a basic robot
					//INPUT - Prompts user for quantity to buy
			cout << "\nHow many would you like to buy? ";
			quantity = GetAndCheckInt(1, 3);


			//Creates new node and adds data
			newNode = new saleNode;
			newNode->next = NULL;
			newNode->robot = "Basic i-Robot";
			newNode->price = 20000;
			newNode->qty = quantity;

			//PROCESSING - IF-THEN-ELSE - Used to check
			//if the list is empty and add the node
			if (head == NULL)
			{
				head = newNode;
				tail = newNode;
			} else
			{
				tempPtr = head;
				while (tempPtr->next != NULL)
				{
					tempPtr = tempPtr->next;
				}
				tempPtr->next = newNode;
				tail = newNode;
			}

			//INPUT - Prompts user to buy more
			do
			{
				cout << "\nWould you like to buy more? ";
				answer = GetAndCheck('Y', 'N');
			} while (answer == 1);

			//PROCESSING - IF-THEN - Used to check if
			//answers is N to checkout and exit
			if (answer == 'N')
			{
				CheckOut(head, outfile);
				exit = true;
			}
			break;
		case DESTROYER:	//Purchases a Bomb Destroyer Robot
						//INPUT - Prompts user for quantity to buy
			cout << "\nHow many would you like to buy? ";
			quantity = GetAndCheckInt(1, 3);
			newNode = new saleNode;
			newNode->next = NULL;
			newNode->robot = "Bomb Destroyer";
			newNode->price = 35000;
			newNode->qty = quantity;

			//PROCESSING - IF-THEN-ELSE - Used to check
			//if the list is empty and add the node
			if (head == NULL)
			{
				head = newNode;
				tail = newNode;
			} else
			{
				tempPtr = head;
				while (tempPtr->next != NULL)
				{
					tempPtr = tempPtr->next;
				}
				tempPtr->next = newNode;
				tail = newNode;
			}

			//INPUT - Prompts user to buy more
			do
			{
				cout << "\nWould you like to buy more? ";
				answer = GetAndCheck('Y', 'N');
			} while (answer == 1);

			//PROCESSING - IF-THEN - Used to check if
			//answers is N to checkout and exit
			if (answer == 'N')
			{
				CheckOut(head, outfile);
				exit = true;
			}
			break;

		case ULTRA_BOT:	//Purchases an Ultra-Bot robot
						//INPUT - Prompts user for quantity to buy
			cout << "\nHow many would you like to buy? ";
			quantity = GetAndCheckInt(1, 3);
			newNode = new saleNode;
			newNode->next = NULL;
			newNode->robot = "Ultra-Bot";
			newNode->price = 99999;
			newNode->qty = quantity;

			//PROCESSING - IF-THEN-ELSE - Used to check
			//if the list is empty and add the node
			if (head == NULL)
			{
				head = newNode;
				tail = newNode;
			} else
			{
				tempPtr = head;
				while (tempPtr->next != NULL)
				{
					tempPtr = tempPtr->next;
				}
				tempPtr->next = newNode;
				tail = newNode;
			}

			//INPUT - Prompts user to buy more
			do
			{
				cout << "\nWould you like to buy more? ";
				answer = GetAndCheck('Y', 'N');
			} while (answer == 1);

			//PROCESSING - IF-THEN - Used to check if
			//answers is N to checkout and exit
			if (answer == 'N')
			{
				CheckOut(head, outfile);
				exit = true;
			}
			break;
		}
	} while (!exit);
}

/*************************************************************************
 *
 * FUNCTION CheckOut
 *________________________________________________________________________
 * This function allows users to check out items
 *________________________________________________________________________
 ************************************************************************/
void BombClass::CheckOut(saleNode *head, ofstream &outfile)
{
	//variables for checkout
	float subTotal;
	float total;
	float tax;
	char data;
	int searchReturn = -1;
	string tempCompanyName;
	string tempStreetAddress;
	string tempStateAddress;
	string tempTestimonial;
	saleNode *tempPtr;

	subTotal = 0;
	total = 0;
	tax = 0;

	outfile.open("CustomersToAdd.txt", std::fstream::app);

	//PROCESSING - DO-WHILE - Used to ask the user if they're on the list
	do
	{
		cout << "\nAre you already a customer on our list?: ";
		data = GetAndCheck('Y', 'N');
	} while (data == 1);

	//PROCESSING - IF-THEN-ELSE - If user is not on the list their info
	//			   is requested
	if (data == 'N')
	{
		//INPUT - Prompts the user for their information
		cout << "\nEnter your data to proceed with purchase:\n\n";

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

		//OUTPUT - Writes the customer's information to file
		outfile << tempCompanyName << endl;
		outfile << tempStreetAddress << endl;
		outfile << tempStateAddress << endl;
		outfile << tempTestimonial << endl;

		//OUTPUT - Prints receipt
		cout << "-------------------------------------" << endl << right
			<< setw(22) << "I-ROBOT" << endl << setw(25) << "SALES RECEIPT"
			<< endl << "-------------------------------------" << endl
			<< left << setw(9) << "Name: " << tempCompanyName << endl
			<< setw(9) << "Address: " << tempStreetAddress << endl
			<< setw(9) << " " << tempStateAddress << endl
			<< "-------------------------------------" << endl;

		tempPtr = head;

		//PROCESSING - WHILE - Used to traverse the list and print the
		//			   items purchased
		while (tempPtr != NULL)
		{
			cout << left << setw(24) << tempPtr->robot << " $" << fixed
					<< setprecision(2) << right << setw(11)
					<< tempPtr->price * tempPtr->qty << endl
					<< tempPtr->qty
					<< " @ $" << tempPtr->price << endl << endl;
			subTotal = subTotal + (tempPtr->price * tempPtr->qty);

			tempPtr = tempPtr->next;
		}

		//PROCESSING - Calculates tax and grand total
		tax = (subTotal * CA_TAX) / 100;
		total = subTotal + tax;

		//OUTPUT - Prints the last part of the receipt
		cout << "-------------------------------------" << endl << left
				<< setw(25) << "SUBTOTAL"
				<< "$" << right << setw(11)
				<< subTotal << endl << "Tax CA %"
				<< left << setw(17) << CA_TAX
				<< "$" << right << setw(11) << tax
				<< endl << left << setw(25)
				<< "TOTAL" << "$" << right
				<< setw(11) << total << endl
				<< "-------------------------------------"
				<< endl << setw(32)
				<< "Thank you for your purchase" << endl << setw(28)
				<< "Tip the programmer!" << endl << endl;

		NeedToAddMembers = true;
	}
	else
	{
		do
		{
			cout << endl;
			cout << "Company Name: ";
			getline(cin, tempCompanyName);
			cout << endl;
			searchReturn = SearchCompanyName(tempCompanyName);
			if (searchReturn == -1)
			{
				cout << "\n\nCompany is not in our system!\n\n";
			}
		} while (searchReturn == -1);

		if (searchReturn != -1)
		{
			cout << tempCompanyName << " found!\n\n";

			list[searchReturn]->SetRevcievedPamphlet("Yes");

			cout << "-------------------------------------"
					<< endl << right
					<< setw(22) << "I-ROBOT" << endl << setw(25)
					<< "SALES RECEIPT" << endl
					<< "-------------------------------------"
					<< endl << left
					<< setw(9) << "Name: "
					<< list[searchReturn]->GetCompanyName()
					<< endl << setw(9)
					<< "Address: "
					<< list[searchReturn]->GetStreetAddress()
					<< endl << setw(9) << " "
					<< list[searchReturn]->GetStateAddress() << endl
					<< "-------------------------------------" << endl;

			tempPtr = head;

			while (tempPtr != NULL)
			{
				cout << left << setw(24) << tempPtr->robot << " $"
						<< fixed
						<< setprecision(2) << right
						<< setw(11)
						<< tempPtr->price * tempPtr->qty
						<< endl << tempPtr->qty
						<< " @ $" << tempPtr->price
						<< endl << endl;
				subTotal = subTotal + (tempPtr->price * tempPtr->qty);
				tempPtr = tempPtr->next;
			}

			tax = (subTotal * CA_TAX) / 100;
			total = subTotal + tax;

			cout << "-------------------------------------"
					<< endl << left
					<< setw(25) << "SUBTOTAL" << "$" << right << setw(11)
					<< subTotal << endl << "Tax CA %" << left << setw(17)
					<< CA_TAX << "$" << right << setw(11) << tax
					<< endl << left
					<< setw(25) << "TOTAL" << "$" << right
					<< setw(11) << total
					<< endl << "-------------------------------------"
					<< endl
					<< setw(32) << "Thank you for your purchase" << endl
					<< setw(36) << "Your robot(s) will ship in 5-7 days"
					<< endl
					<< endl;
		}
	}



	outfile.close();
	outfile.clear();
}
