#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenueScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangMainScreen.h"
using namespace std;
class clsMainScreen :protected clsScreen
{
private:
	enum enMainMenueOptions {
		enListClients = 1, enAddNewClient = 2, enDeleteClient = 3,
		enUpdateClient = 4, enFindClient = 5, enShowTransactionsMenue = 6,
		enManageUsers = 7,enLoginRegister=8 , enCurrencyExchangMainScreen=9,enLogout = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "\tChoose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
		return Choice;
	}

	static void _GoBackToMainMenue() {
		cout << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();

	}

	static void _ShowClientList() {
		clsClientListScreen::ShowClientList();
	}

	static void  _ShowAddNewClientScreen() {
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen() {
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {
		clsUpdateClientScreen::ShowUpdateClientScreen();

	}
	static void _ShowFindClientScreen() {
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenueScreen() {
		clsTransactionsMenueScreen::ShowTransactionsMenueScreen();
	}

	static void _ShowManageUsersScreen() {
		clsManageUsersScreen::ShowManageUsersScreen();

	}
	static void _ShowLoginRegisterScreen() {
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMainScreen() {
		clsCurrencyExchangMainScreen::ShowCurrencyExchangemainScreen();
	}

	static void _Logout() {
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption) {
		switch (MainMenueOption)
		{
		case clsMainScreen::enListClients: {
			system("cls");
			_ShowClientList();
			_GoBackToMainMenue();
			break;
		}

		case clsMainScreen::enAddNewClient: {
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case clsMainScreen::enDeleteClient: {
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case clsMainScreen::enUpdateClient: {
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case clsMainScreen::enFindClient: {
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case clsMainScreen::enShowTransactionsMenue: {
			system("cls");
			_ShowTransactionsMenueScreen();
			_GoBackToMainMenue();
			break;
		}

		case clsMainScreen::enManageUsers: {
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enLoginRegister: {
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enCurrencyExchangMainScreen: {
			system("cls");
			_ShowCurrencyExchangeMainScreen();
			_GoBackToMainMenue();
			break;
		}


		case clsMainScreen::enLogout: {
			system("cls");
			_Logout();
			break;
		}


		}
	}
public:
	static void ShowMainMenue() {
		system("cls");
		_DrawScreenHeader("Main Menue");

		cout << left << setw(34) << "" << "=====================================================\n\n";
		cout << setw(34) << left << "" << "\t\t\tMain Menue\n";
		cout << left << setw(34) << "\n" << " =====================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t\t[10] Logout.\n";
		cout << left << setw(34) << "\n" << " =====================================================\n";

		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

	}
};

