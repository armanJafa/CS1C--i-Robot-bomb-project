/**********************************************************
 * AUTHOR 		 : Austin, Kevin, Arman, Augusto
 * STUDENT ID 	 : 364965
 * Project #2    : Project #2
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 5/13/15
 **********************************************************/

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Date.h"

//base class
class Customer
{
private:

	//private data members for all customers
	string companyName;
	string streetAddress;
	string stateAddress;
	string customerRating;
	string testimonial;
	float amountSpent;
	Date pamphletSentDate;
	string field;

public:

	Customer();
	//default constructor

	Customer(string, string, string, string, string);
	//non-default constructor

	virtual ~Customer();
	//destructor

	virtual void Print();
	//print method

	//....bunch of getters and setters below this:
};

#endif /* CUSTOMER_H_ */
