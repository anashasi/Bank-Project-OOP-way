#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsDeleteUserScreen:protected clsScreen
{

private:
	static void _PrintUser(clsUser user) {
		cout << "\n\nUser Card:";
		cout << "\n________________________";
		cout << "\nFirstName   : " << user.FirstName;
		cout << "\nLastName    : " << user.LastName;
		cout << "\nFull Name   : " << user.FullName();
		cout << "\nEmail       : " << user.Email;
		cout << "\nPhone       : " << user.Phone;
		cout << "\nUserName    : " << user.UserName;
		cout << "\nPassword    : " << user.Password;
		cout << "\nPermission  : " << user.Permission;
		cout << "\n________________________\n";
	}



public:
	static void ShowDeleteUserScreen() {
		_DrawScreenHeader("Delete User");

		string Username = "";
		cout << "\nPlease enter User UserName to delete. ";
		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username)) {
			cout << "\nUser not found please enter another UserName: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser delUser = clsUser::Find(Username);

		_PrintUser(delUser);

		cout << "\nAre you sure you want to delelte this User? [Y/N] ";

		char ansewr = 'n';
		cin >> ansewr;

		if (ansewr == 'Y' || ansewr == 'y') {
			if (delUser.Delete()) {
				cout << "\nUser was successfully Deleted.\n";
				_PrintUser(delUser);

			}
			else {
				cout << "\nError User Was not Deleted\n";
			}
		}
	}
	
};

