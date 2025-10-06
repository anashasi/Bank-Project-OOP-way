#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsAddNewClientScreen:protected clsScreen
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
		cout << "\nLastName    : " << Client. LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc.Number  : " << Client.GetAccountNumber();
		cout << "\nPinCode     : " << Client.PinCode;
		cout << "\nAcc.Balance : " << Client.AccountBalance;
		cout << "\n________________________\n";
	}
public:
	static void ShowAddNewClientScreen() {
		if (!CheckAccessRihgts(clsUser::enPermission::enAddNewClient)) {
			return;
		}
		_DrawScreenHeader("Add New Client");
		string AccountNumber = "";
		cout << "Enter AccountNumber to Add new client. ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Account number is already exist, chose another one. ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadCLientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject: {
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsBankClient::svSucceeded: {
			cout << "\nNew Client Added successfully.";
			_PrintClientCard(NewClient);
			break;
		}

		case clsBankClient::svFaildAccountNumberExists: {
			cout << "\nError Faild to add new client because the account number already exists.";
			break;
		}
		}

	}
};

