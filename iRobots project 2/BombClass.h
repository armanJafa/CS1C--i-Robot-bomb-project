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
	ADMIN_OPTIONS,
	VIEW_HELP
};

//used for admin menu
enum AdminChoice
{
	ADMIN_MENU_EXIT,
	VIEW_LIST,
	ADD_MEMBERS,
	VIEW_KEY_LIST,
	DELETE_MEMBERS,
	CHANGE_DATA
};

//used for purchase menu
enum RobotChoice
{
	SALE_EXIT,
	BASIC,
	DESTROYER,
	ULTRA_BOT,
};

//used for purchase list
struct saleNode
{
	string 	  robot;
	float	  price;
	int	   	  qty;
	saleNode *next;
};

//const for california sales tax
const float CA_TAX = 8.25;


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

	void ViewTestimonials();
	//views the current testimonials

	void WriteTestimonials();

	int SearchCompanyName(string);
	//search company name in order to write a tesimonial

	bool EnterAdminPassword();
	//enter a password to access menu

	void DisplayHelpPage();
	//Displays help menu

	void SaveBetweenExecutions();
	//saves file between executions

	void RequestAPamphlet(ofstream&);
	//users can request a pamphlet

	void DisplayKeyCustomers();
	//admin can view key customers

	int PurchaseMenu();
	//customers can purchase robots

	void Purchase(ofstream &outfile);
	//the actual purchase location code

	void CheckOut(saleNode *head, ofstream &outfile);
	//will checkout all the robots bought

	void DeleteMembers();
	//will delete members

	void ChangeData();
	//chnages data



private:

	//USING CLASS TEMPLATES
	vector<Customer*> list; //list of customer pointers
	//without pointer, only stores copies

	bool NeedToAddMembers;


	int GetAndCheckInt(int int1, //IN -  lowest allowable parameter for
								 //      correct values that need to be
								 //      error checked.
			int int2);	 		 //IN -  highest allowable parameter for
								 //      correct values that need to be
								 //      error checked.

	int AdminMenu();
	//helper function, can be viewd within AdministrationPage() only


	//helper function, can be viewd within AdministrationPage() only
	void DisplayMemberList();

	void DisplayKeyMemberList();
	//displays the key members

	void AddMembers();
	//adds members

	void DisplayNewMembers();
	//displays new members who need to be added

	char GetAndCheck(char val1, char val2);
	//checks char values

	void SendPamphletToListCustomers();
	//sends pamphlet
};

#endif /* BOMBCLASS_H_ */

