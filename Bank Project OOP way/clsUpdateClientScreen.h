#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateClientScreen:protected clsScreen
{
private:

	static void _ReadCLientInfo(clsBankClient& Client) {
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Eamil: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccountBalance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

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
	static void ShowUpdateClientScreen() {
		if (!CheckAccessRihgts(clsUser::enPermission::enUpdateClient)) {
			return;
		}
		_DrawScreenHeader("Update Client");
		string Accountnumber = "";
		cout << "\nPlease Enter client Account Number: ";
		Accountnumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(Accountnumber)) {
			cout << "\nAccount Number not found, chose another one: ";
			Accountnumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(Accountnumber);
		 _PrintClientCard(Client);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";

		_ReadCLientInfo(Client);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError account was not saved because it's Empty";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nClient Info Updated successfully.";
			_PrintClientCard(Client);
			break;

		}
	}
};

