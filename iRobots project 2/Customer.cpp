/**********************************************************
 * AUTHOR 		 : Austin, Kevin, Arman, Augusto
 * STUDENT ID 	 : 364965
 * Project #2    : Project #2
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 5/13/15
 **********************************************************/

#include "Customer.h"

//default costructor
Customer::Customer()
{
	companyName.clear();
	streetAddress.clear();
	stateAddress.clear();
	customerRating.clear();
	testimonial.clear();
	amountSpent = 0.0;
	field.clear();
}

//non-default constructor
Customer::Customer(string tempCompanyName, string tempStreetAddress,
	string tempStateAddress, string tempCustomerRating, string tempField)
{
	//sets all data to the file data
	this->companyName = tempCompanyName;
	this->streetAddress = tempStreetAddress;
	this->stateAddress = tempStateAddress;
	this->customerRating = tempCustomerRating;
	this->field = tempField;

	amountSpent = 0;

}

//destructor
Customer::~Customer()
{

}

//virtual function, base data printed
void Customer::Print()
{

	cout << companyName << endl;
	cout << streetAddress << endl;
	cout << stateAddress << endl;
	cout << customerRating << endl;
	if (field != "key")
	{
		cout << field;
		cout << endl;
	}

}
