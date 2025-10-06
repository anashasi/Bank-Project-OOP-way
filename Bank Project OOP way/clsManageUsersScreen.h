#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersMenueOptions {
		enListUsers=1,enAddNewUser=2,enDeleteUser=3,
		enUpdateUser=4,enFindUser=5,enMainMenue=6
	};

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "\tChoose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	static void _GoBackToManageUsersMenue() {
		cout << "\nPress any key to Go back to Manage Users Menue.......";
		system("pause>0");
		ShowManageUsersScreen();

	}

	static void _ShowUsersList() {
		clsUsersListScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	
	static void _ShowDeleteUserScreen() {
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();

	}

	static void _PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption) {
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOptions::enListUsers: {
			system("cls");
			_ShowUsersList();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptions::enAddNewUser: {
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptions::enDeleteUser: {
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptions::enUpdateUser: {
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptions::enFindUser: {
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptions::enMainMenue: {
			
			break;
		}

		}
	}
public:
	static void ShowManageUsersScreen() {
		if (!CheckAccessRihgts(clsUser::enPermission::enManageUsersMenue)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("Manage Users Menue");

		cout << left << setw(34) << "" << "=====================================================\n\n";
		cout << setw(34) << left << "" << "\t\t\tManage Users Menue\n";
		cout << left << setw(34) << "\n" << " =====================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t\t[4] Update User .\n";
		cout << setw(37) << left << "" << "\t\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t\t[6] Main Menue.\n";
		cout << left << setw(34) << "\n" << " =====================================================\n";

		_PerfromManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}
};

