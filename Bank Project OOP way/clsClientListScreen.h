#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsClientListScreen:protected clsScreen
{
private:
	static void PrintClientRecordLine(clsBankClient Client) {
		cout << left << setw(5) << "" << "|" << left << setw(15) << Client.GetAccountNumber();
		cout << left << setw(5) << "" << "|" << left << setw(15) << Client.FullName();
		cout << left << setw(5) << "" << "|" << left << setw(13) << Client.Phone;
		cout << left << setw(5) << "" << "|" << left << setw(15) << Client.Email;
		cout << left << setw(5) << "" << "|" << left << setw(10) << Client.PinCode;
		cout << left << setw(5) << "" << "|" << left << setw(10) << Client.AccountBalance;
	}
public:
	static void ShowClientList() {
		if (!CheckAccessRihgts(clsUser::enPermission::enListClients)) {
			return;
		}
		vector <clsBankClient> vClients = clsBankClient::GetClientList();
		string Title = "Client List";
		string Subtitle ="("+ to_string(vClients.size()) + ") Client(s).";
		
		clsScreen::_DrawScreenHeader(Title,Subtitle);

		cout <<left<<setw(5)<<""<< "--------------------------------------------------------------------------------------------------------------\n";
		cout << left << setw(5) << "" << "|" << left << setw(15) << "Account Number";
		cout << left << setw(5) << "" << "|" << left << setw(15) << "Client Name";
		cout << left << setw(5) << "" << "|" << left << setw(13) << "Phone";
		cout << left << setw(5) << "" << "|" << left << setw(15) << "Email";
		cout << left << setw(5) << "" << "|" << left << setw(10) << "Pin Code";
		cout << left << setw(5) << "" << "|" << left << setw(10) << "Balance";
		cout << endl << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";

		if (vClients.size() == 0) {
			cout << "\n\t\t\t\t\tNO CLIENTS FOUND TO LIST.\n";
			cout << "\n---------------------------------------------------------------------------------------------------------\n";

		}
		else {
			for (clsBankClient Client : vClients) {
				PrintClientRecordLine(Client);
				cout << endl;
			}
		}
		cout << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";
	}
};

