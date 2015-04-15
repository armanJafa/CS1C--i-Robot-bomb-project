/**********************************************************
 * AUTHOR 		 : Austin, Kevin, Arman, Augusto
 * STUDENT ID 	 : 364965
 * Project #2    : Project #2
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 5/13/15
 **********************************************************/
#include"BombClass.h"

namespace AustinsNameSpace
{
	int choice = 0;
	ifstream infile;
	BombClass bombInventory;
}

using namespace AustinsNameSpace;

int main()
{


	//function call to generate list
	bombInventory.CreateMemberList(infile);

	//do while for looping program
	do
	{
		//will pull up menu options
		choice = bombInventory.CustomerMenu();

		// will exit if 0
		if (choice != EXIT)
		{
			//seitch cases
			switch (choice)
			{

			//only option avalible for customers at this time
			case VIEW_PAMPHLET:

				bombInventory.DisplayPamphlet();
				break;

			//only option avalible for Admin at this time
			case ADMIN_OPTIONS:

				cout << endl;
				if(bombInventory.EnterAdminPassword())
				{
					bombInventory.AdministrationPage();
				}

				break;

			}
		}

	} while (choice != EXIT);


	return 0;
}
