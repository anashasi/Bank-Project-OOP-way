#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsUpdateUserScreen:protected clsScreen
{
private:

	static int _ReadUserPermission() {
		int permission = 0;
		char choice = 'n';
		cout << "\nDo you want to give user full access? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			return -1;

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow client list? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			permission += clsUser::enPermission::enListClients;

		cout << "\nAdd new client ? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			permission += clsUser::enPermission::enAddNewClient;

		cout << "\nDelete client ? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			permission += clsUser::enPermission::enDeleteClient;

		cout << "\nUpdate client ? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			permission += clsUser::enPermission::enUpdateClient;

		cout << "\nFind client ? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			permission += clsUser::enPermission::enFindClient;

		cout << "\nTransaction Menue ? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			permission += clsUser::enPermission::enTransactionMenue;

		cout << "\nManage Users Menue ? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			permission += clsUser::enPermission::enManageUsersMenue;

		cout << "\nshow login Register list ? [Y/N] ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			permission += clsUser::enPermission::enLoginRegister;

		return permission;

	}





	static void _ReadUserInfo(clsUser& user) {
		cout << "\nEnter FirstName: ";
		user.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		user.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Eamil: ";
		user.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		user.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		user.Password = clsInputValidate::ReadString();

		user.Permission = _ReadUserPermission();
	}

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
	static void ShowUpdateUserScreen() {
		_DrawScreenHeader("Update User");
		string Username = "";
		cout << "\nPlease Enter User UserName: ";
		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username)) {
			cout << "\nUsername not found, chose another one: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);
		_PrintUser(User);

		char answer = 'n';
		cout << "Are you sure you want to update this user? [Y/N]";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			cout << "\n\nUpdate User Info:";
			cout << "\n____________________\n";

			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResult;
			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::svFaildEmptyObject: {
				cout << "\nUpdate User failed Empty object.\n";
				break;
			}

			case clsUser::svSucceeded: {
				cout << "\nUpdate user done successfully.\n";
				_PrintUser(User);
				break;
			}

			}
		}
	}
	
};

