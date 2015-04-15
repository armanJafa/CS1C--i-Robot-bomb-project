/**********************************************************
 * AUTHOR 		 : Austin, Kevin, Arman, Augusto
 * STUDENT ID 	 : 364965
 * Project #2    : Project #2
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 5/13/15
 **********************************************************/

#ifndef KEYCUSTOMER_H_
#define KEYCUSTOMER_H_

#include "Customer.h"

//derived class
class KeyCustomer : public Customer
{
public:

	KeyCustomer();
	//default constructor

	KeyCustomer(string, string, string, string, string);
	//non-default constructor

	virtual ~KeyCustomer();
	//Destructor

	virtual void Print();
	//virtual print method

private:

	//extra field if key customer
	string keyField;

};

#endif /* KEYCUSTOMER_H_ */
