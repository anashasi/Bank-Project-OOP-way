#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsFindClientScreen:protected clsScreen
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
	static void ShowFindClientScreen() {
		if (!CheckAccessRihgts(clsUser::enPermission::enFindClient)) {
			return;
		}
		_DrawScreenHeader("Find Client");

		string AccountNumber = "";
		cout << "\nPlease enter client AccountNumber to Find. ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client not found please enter another AccountNumber: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty()) {
			cout << "\nClient Found\n";
		}

		else {
			cout << "\nClient was not Found\n";
		}
		_PrintClientCard(Client);
	}
};

