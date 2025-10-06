#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindUserScreen:protected clsScreen
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
	static void ShowFindUserScreen() {
		_DrawScreenHeader("Find User");
		string Username = "";
		cout << "\nPlease Enter User UserName: ";
		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username)) {
			cout << "\nUsername not found, chose another one: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);
		
		if (!User.IsEmpty()) {
			cout << "\nUser Found.\n";
			_PrintUser(User);
		}
		else
			cout << "\nUser is not found.\n";


	}
};

