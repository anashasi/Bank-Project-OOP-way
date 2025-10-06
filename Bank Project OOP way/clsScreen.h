#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string SubTitle="") {
		cout << "\t\t\t\t  -----------------------------------------------------\n";
		cout <<"\t\t\t\t |\t\t        "<< left << setw(31)<<Title  << "|";
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t |\t\t        " << left << setw(31) << SubTitle<< "|";
		}

		cout << "\n\t\t\t\t  -----------------------------------------------------\n";

		cout << "\t\t\t\t" <<"  User: " <<CurrentUser.UserName<<"\t\t\t\tDate: " << clsDate::DateToString(clsDate())<<endl<<endl<<endl;
		//cout << "\n\t\t\t\t  -------------------------------------------------------\n\n";

	}
	static bool CheckAccessRihgts(clsUser::enPermission Permission) {
		if (!CurrentUser.CheckAccessPermission(Permission)) {
			cout << "\t\t\t\t  -----------------------------------------------------------------\n";
			cout << "\n\t\t\t\t\t\t"<< left << setw(31) << "Access Denied! Contact Your Admin.\n";
			cout << "\n\t\t\t\t -------------------------------------------------------------------\n\n";

			return false;
		}

		else
			return true;
	}
};

