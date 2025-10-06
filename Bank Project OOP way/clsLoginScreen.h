#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include"clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	

	static bool _Login() {
		bool LoginFaild = false;
		short FailedTrials = 0;
		string Username, Password;

		do {
			if (LoginFaild) {
				FailedTrials++;
				cout << "\nInvalid Username/Password";
				cout << "\nYou have " << 3- FailedTrials << " to login.\n\n";
			}
			if (FailedTrials == 3) {
				cout << "\nYou are locked after 3 faild trials\n\n";
				return false;
			}
			cout << "\nPlease enter Username: ";
			cin >> Username;
			cout << "\nPlease enter Password: ";
			cin >> Password;
			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		 CurrentUser.RegisterLogin();
		 clsMainScreen::ShowMainMenue();
		 return true;
	}

public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}
};

