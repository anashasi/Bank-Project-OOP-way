#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
private:
	static void _PrintBalanceRecordLine(clsBankClient Client) {
		cout << left << setw(7) << "" << "|" << left << setw(25) << Client.GetAccountNumber();
		cout << left << setw(7) << "" << "|" << left << setw(30) << Client.FullName();
		cout << left << setw(7) << "" << "|" << left << setw(25) << Client.AccountBalance;
	}

public:
	static void ShowTotalBalancesScreen() {

		vector <clsBankClient> vClients = clsBankClient::GetClientList();
		_DrawScreenHeader("Total Balances","Client List ("+to_string(vClients.size())+ ") Client(s).");

		cout << left << setw(8) << "\n" << "---------------------------------------------------------------------------------------------------------\n";
		cout << left << setw(7) << "" << "|" << left << setw(25) << "Account Number";
		cout << left << setw(7) << "" << "|" << left << setw(30) << "Client Name";
		cout << left << setw(7) << "" << "|" << left << setw(25) << "Balance";
		cout << left << setw(8) << "\n" << "---------------------------------------------------------------------------------------------------------\n";
		double TotalBalance = clsBankClient::GetTotalBalances();
		if (vClients.size() == 0) {
			cout << "\n\t\t\t\t\tNO CLIENTS FOUND TO LIST.\n";
		}
		else {
			for (clsBankClient Client : vClients) {
				_PrintBalanceRecordLine(Client);
				cout << endl;
			}

		}
		cout << left << setw(7) << "" << "---------------------------------------------------------------------------------------------------------\n";

		cout << left << setw(7) << "" << "\n\t\t\tTotal Balance: " << TotalBalance << "\t(" << clsUtil::NumberToText(TotalBalance) << ")" << endl << endl;

	}
};

