#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsDeleteClientScreen:protected clsScreen
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

public:
	static void ShowDeleteClientScreen() {
		if (!CheckAccessRihgts(clsUser::enPermission::enDeleteClient)) {
			return;
		}
		_DrawScreenHeader("Delete Client");

		string AccountNumber = "";
		cout << "\nPlease enter client AccountNumber to delete. ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client not found please enter another AccountNumber: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client);

		cout << "\nAre you sure you want to delelte this client? [Y/N] ";

		char ansewr = 'n';
		cin >> ansewr;

		if (ansewr == 'Y' || ansewr == 'y') {
			if (Client.Delete()) {
				cout << "\nClient was successfully Deleted.\n";
				_PrintClientCard(Client);

			}
			else {
				cout << "\nError Client Was not Deleted\n";
			}
		}
	}
};

