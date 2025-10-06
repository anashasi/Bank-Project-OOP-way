#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsUsersListScreen:protected clsScreen
{
private:
	static void _PrintUserLineRecord(clsUser User) {
		cout << left << setw(5) << "" << "|" << left << setw(15) << User.UserName;
		cout << left << setw(5) << "" << "|" << left << setw(15) << User.FullName();
		cout << left << setw(5) << "" << "|" << left << setw(13) << User.Phone;
		cout << left << setw(5) << "" << "|" << left << setw(15) << User.Email;
		cout << left << setw(5) << "" << "|" << left << setw(10) << User.Password;
		cout << left << setw(5) << "" << "|" << left << setw(10) << User.Permission;
	}

public:
	static void ShowUsersList() {
		vector <clsUser> vUsers;
		vUsers = clsUser::GetUsersList();
		
		string Title = "Users List";
		string subtitle = "(" + to_string(vUsers.size()) + ") User(s)";

		_DrawScreenHeader(Title, subtitle);

		cout << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";
		cout << left << setw(5) << "" << "|" << left << setw(15) << "UserName";
		cout << left << setw(5) << "" << "|" << left << setw(15) << "Full Name";
		cout << left << setw(5) << "" << "|" << left << setw(13) << "Phone";
		cout << left << setw(5) << "" << "|" << left << setw(15) << "Email";
		cout << left << setw(5) << "" << "|" << left << setw(10) << "Password";
		cout << left << setw(5) << "" << "|" << left << setw(10) << "Permission";
		cout << endl << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";

		if (vUsers.size() == 0)
			cout << "\n\t\t\t\t\t\tNO USERS FOUND TO LIST.\n";

		else {
			for (clsUser User : vUsers) {
				_PrintUserLineRecord(User);
				cout << endl;
			}
		}
		cout << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";

	}
};

