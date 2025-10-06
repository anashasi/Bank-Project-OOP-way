#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsWithdrawScreen:protected clsScreen
{
private:
	static void _PrintClientCard(clsBankClient Client) {

		cout << "\n\nClient Card:";
		cout << "\n________________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc.Number  : " << Client.GetAccountNumber();
		cout << "\nPinCode     : " << Client.PinCode;
		cout << "\nAcc.Balance : " << Client.AccountBalance;
		cout << "\n________________________\n";
	}

	static string _ReadAccountNumber() {
		string s = "";
		s = clsInputValidate::ReadString();
		return s;
	}

public:
	static void ShowWithdrawScreen() {
		_DrawScreenHeader("Withdraw");
		cout << "\nEnter Client AccountNumber?  ";
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccountNumber Was not found, enter another AccountNumber: ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client);


		double Amount = 0;
		cout << "\nPlease Enter Deposit Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		if (Client.AccountBalance < Amount) {
			cout << "\nCannot Withdraw, insuffecient Balance.\n";
			cout << "\nAmount to withdraw: " << Amount << endl;
			cout << "\nYour Account Balance: " << Client.AccountBalance << endl;
		}
		else {
			char choice = 'n';
			cout << "\nAre you sure to preform this transaction? [Y/N] : ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				Client.Withdraw(Amount);
				cout << "\nTransaction Done Successfully.\n";
				cout << "\nNew Client Balance: " << Client.AccountBalance << endl << endl;
			}
			else {
				cout << "\nOpreation canceld.\n";
			}
		}
	}
};

