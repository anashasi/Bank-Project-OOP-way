#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsLoginRegisterScreen:protected clsScreen
{
private:
	static void _PrintLoginRecordLine(clsUser::stLoginRegisterRecord LoginRecord) {
		cout << left << setw(5) << "" << "|" << left << setw(25) << LoginRecord.DateTime;
		cout << left << setw(5) << "" << "|" << left << setw(15) << LoginRecord.username;
		cout << left << setw(5) << "" << "|" << left << setw(15) << LoginRecord.password;
		cout << left << setw(5) << "" << "|" << left << setw(13) << LoginRecord.permission;

	}

public:
	static void ShowLoginRegisterScreen() {
		if (!CheckAccessRihgts(clsUser::enPermission::enLoginRegister)) {
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterDataFromFile();

		string Title = "Login Register List";
		string Subtitle = "(" + to_string(vLoginRegisterRecord.size()) + ") Login(s).";

		clsScreen::_DrawScreenHeader(Title, Subtitle);

		cout << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";
		cout << left << setw(5) << "" << "|" << left << setw(25) << "Date-Time";
		cout << left << setw(5) << "" << "|" << left << setw(15) << "Username";
		cout << left << setw(5) << "" << "|" << left << setw(15) << "Password";
		cout << left << setw(5) << "" << "|" << left << setw(13) << "Permission";
		cout << endl << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";

		if (vLoginRegisterRecord.size() == 0) {
			cout << "\n\t\t\t\t\tNO LOGIN REGISTER FOUND TO LIST.\n";
			cout << "\n---------------------------------------------------------------------------------------------------------\n";

		}
		else {
			for (clsUser::stLoginRegisterRecord LoginRecord : vLoginRegisterRecord) {
				_PrintLoginRecordLine(LoginRecord);
				cout << endl;
			}
		}
		cout << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";
	}
	
};

