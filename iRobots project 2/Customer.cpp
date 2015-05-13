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
	amountSpent = NULL;
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

	amountSpent = new float;
	*amountSpent = 0;

}

Customer::Customer(string tempCompanyName, string tempStreetAddress,
		string tempStateAddress, string tempTestimonial)
{

	this->companyName = tempCompanyName;
	this->streetAddress = tempStreetAddress;
	this->stateAddress = tempStateAddress;
	this->testimonial = tempTestimonial;

	amountSpent = new float;
	*amountSpent = 0;
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

void Customer::SetRevcievedPamphlet(string tempPamphlet)
{

	this->pamphletSent = tempPamphlet;

}

/*************************************************************************
 *
 * FUNCTION Default Copy function
 *________________________________________________________________________
 * This function will copy the elements of one object into a new object.
 * Used when objects are passed by value or assigned to one another
 *________________________________________________________________________
 ************************************************************************/
Customer::Customer(Customer &anotherNode) // object to be made a
// copy
{
	//SETS ALL DATA MEMBERS TO OBJECT BEING PASSED IN BASED OFF THE OBJECT
	//THAT THE FUNCTION IS CALLED FROM

	companyName = anotherNode.companyName;
	streetAddress = anotherNode.streetAddress;
	stateAddress = anotherNode.stateAddress;
	testimonial = anotherNode.testimonial;

	customerRating = anotherNode.customerRating;
	field = anotherNode.field;
	pamphletSent = anotherNode.pamphletSent;
	amountSpent = new float;
	amountSpent = anotherNode.amountSpent;

	//cout << "\n -copy constructor is called\n" << endl;

}

void Customer::SetCustomerRating(string customerRating)
{

	this->customerRating = customerRating;
}

void Customer::SetAddressRating(string stateAddress, string streetAddress)
{
	this->stateAddress = stateAddress;
	this->streetAddress = streetAddress;
}
void Customer::SetField(string field)
{
	this->field = field;
}

//virtual function, base data printed
void Customer::Print()
{

	cout << setw(25) << companyName << setw(26) << streetAddress << setw(24)
			<< stateAddress << setw(26) << customerRating << setw(24);
	cout << pamphletSent << setw(25);

	if (field != "key")
	{

		cout << field;
		cout << endl;
	}

}

void Customer::PrintKeyCustomer()
{

	if (field == "key")
	{
		cout << setw(25) << companyName << setw(26) << streetAddress << setw(24)
				<< stateAddress << setw(26) << customerRating << setw(24);
		cout << pamphletSent << setw(25);
		cout << field;
		cout << endl;

	}
}

bool Customer::operator >(Customer& otherCustomer)
//Overloaded greater than operator. Used for sorting.
{
	return (companyName > otherCustomer.companyName);
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
