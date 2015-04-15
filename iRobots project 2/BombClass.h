/**********************************************************
 * AUTHOR 		 : Austin, Kevin, Arman, Augusto
 * STUDENT ID 	 : 364965
 * Project #2    : Project #2
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 5/13/15
 **********************************************************/

#ifndef BOMBCLASS_H_
#define BOMBCLASS_H_

#include "Customer.h"

//used for user menu
enum UserChoice
{
	EXIT,
	VIEW_PAMPHLET,
	VIEW_TESTIMONIALS,
	ADD_TESTIMONIALS,
	REQUEST_A_PAMPHLET,
	ORDER_ROBOTS,
	ADMIN_OPTIONS

};

//used for admin menu
enum AdminChoice
{
	ADMIN_MENU_EXIT,
	VIEW_LIST

};

//main container for whole project
class BombClass
{
public:

	BombClass();
	//constructor

	int CustomerMenu();
	//customer main menu

	void AdministrationPage();
	//page used for admin only

	void CreateMemberList(ifstream &infile);
	//creates the initial list

	void DisplayPamphlet();
	//displays pamphlet

	bool EnterAdminPassword();

private:

	vector<Customer*> list; //list of customer pointers
	//without pointer, only stores copies

	int GetAndCheckInt(int int1, //IN -  lowest allowable parameter for
								 //      correct values that need to be
								 //      error checked.
			int int2);	 		 //IN -  highest allowable parameter for
								 //      correct values that need to be
								 //      error checked.

	int AdminMenu();
	//helper function, can be viewd within AdministrationPage() only

	void DisplayMemberList();
	//helper function, can be viewd within AdministrationPage() only
};

#endif /* BOMBCLASS_H_ */
