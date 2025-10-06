#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;
class clsTransferScreen:protected clsScreen
{
private:
	static void _PrintTransferClientCard(clsBankClient Client) {
		cout << "\nClient Card:\n";
		cout << "\n-----------------------\n";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nAcc.Number : " << Client.GetAccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n-----------------------\n\n";
	}
	static string _ReadAccountNumber() {
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccountNumber Was not found, enter another AccountNumber: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient FromClient1) {
		float Amount = 0;
		cout << "\nEnter Transfer Amount: ";
		cin >> Amount;

		while (Amount > FromClient1.AccountBalance) {
			cout << "\nAmount Exceeds Account Balance ,please enter another Amount: ";
			cin >> Amount;
		}
		return Amount;
	}

public :

	static void ShowTransferScreen() {
		_DrawScreenHeader("Transfer Screen");

		cout << "\nEnter Client AccountNumber to TransFer from?  ";

		string AccountNumber1 = _ReadAccountNumber();
		clsBankClient FromClient1 = clsBankClient::Find(AccountNumber1);
		_PrintTransferClientCard(FromClient1);


		cout << "\nEnter Client AccountNumber to TransFer To?  ";

		string AccountNumber2 = _ReadAccountNumber();
		clsBankClient ToClient2 = clsBankClient::Find(AccountNumber2);
		_PrintTransferClientCard(ToClient2);

		float Amount = _ReadAmount(FromClient1);

		char choice = 'n';
		cout << "\nAre you sure you want to preform this opreation? [Y/N] ";
		cin >> choice;

		if (choice == 'y' || choice == 'Y') {

			if (FromClient1.Transfer(ToClient2, Amount)) {
				cout << "\nTransfer done successfully.\n";
			}
			else {
				cout << "\nTransfer Failed.\n";
			}
			
			_PrintTransferClientCard(FromClient1);
			_PrintTransferClientCard(ToClient2);
		}
		else
			cout << "\nOperation canceld.\n\n";
			
	}
};

