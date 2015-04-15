/**********************************************************
 * AUTHOR 		 : Austin, Kevin, Arman, Augusto
 * STUDENT ID 	 : 364965
 * Project #2    : Project #2
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 5/13/15
 **********************************************************/

#include "KeyCustomer.h"

//default constructor
KeyCustomer::KeyCustomer()
{

	keyField.clear();

}

//non-default constructor
KeyCustomer::KeyCustomer(string tempCompanyName, string tempStreetAddress,
	string tempStateAddress, string tempCustomerRating, string tempField)

//calls the base constructor
:Customer(tempCompanyName, tempStreetAddress,
		 tempStateAddress,tempCustomerRating,tempField)
{
	//sets private data field
	this->keyField = tempField;

}

//Destructor
KeyCustomer::~KeyCustomer()
{

}

//virtual method to print extra field in derived class
void KeyCustomer::Print()
{
	//calls base method
	Customer::Print();

	cout << keyField;
	cout << endl;


}

