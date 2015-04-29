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
	pamphletSent.clear();
	field.clear();
}

//non-default constructor
Customer::Customer(string tempCompanyName, string tempStreetAddress,
		string tempStateAddress, string tempCustomerRating, string tempField,
		string tempTestimonial, string pamphletSent)
{
	//sets all data to the file data
	this->companyName = tempCompanyName;
	this->streetAddress = tempStreetAddress;
	this->stateAddress = tempStateAddress;
	this->customerRating = tempCustomerRating;
	this->field = tempField;
	this->testimonial = tempTestimonial;
	this->pamphletSent = pamphletSent;

	amountSpent = 0;

}

Customer::Customer(string tempCompanyName, string tempStreetAddress,
		string tempStateAddress, string tempTestimonial)
{

	this->companyName = tempCompanyName;
	this->streetAddress = tempStreetAddress;
	this->stateAddress = tempStateAddress;
	this->testimonial = tempTestimonial;

	amountSpent = 0;
	pamphletSent = "Yes";

}

string Customer::GetTestimonial()
{

	return testimonial;

}
string Customer::GetCompanyName()
{
	return companyName;

}
string Customer::GetStreetAddress()
{
	return streetAddress;
}

string Customer::GetStateAddress()
{
	return stateAddress;
}

string Customer::GetCustomerRating()
{
	return customerRating;
}

void Customer::SetTestimonial(string testimonial)
{
	this->testimonial = testimonial;

}

string Customer::GetField()
{
	return field;
}

string Customer::GetPamphlet()
{

	return pamphletSent;

}

void Customer:: SetRevcievedPamphlet(string tempPamphlet)
{

	this->pamphletSent = tempPamphlet;

}

//virtual function, base data printed
void Customer::Print()
{

	cout << setw(25) << companyName << setw(26) << streetAddress << setw(24)
			 << stateAddress << setw(26) << customerRating << setw(24);
			 cout << pamphletSent << setw(25);

	//cout << companyName << endl;
	//cout << streetAddress << endl;
	//cout << stateAddress << endl;
	//cout << customerRating << endl;
	//cout << testimonial << endl;
	//cout << pamphletSent << endl;


	if (field != "key")
	{

		cout << field;
		cout << endl;
	}



}

//Overloaded Insertion Operator
//Used for storing the new customer information.
istream& operator >>(istream& input, Customer& customerInput)
{

	cout << "\n\nEnter a customer rating"
			"(Interested <very/not so much>:";
	getline(input, customerInput.customerRating);
	cout << endl;

	cout << "Enter Field(nice to have? Not so much?): ";
	getline(input, customerInput.field);

	return input;
}
