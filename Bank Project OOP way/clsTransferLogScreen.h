#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;
class clsTransferLogScreen:protected clsScreen
{
private:
	static void _PrintTransferRecordLine(clsBankClient::RegisterTransferLog TransferRecord) {

		cout << left << setw(5) << "" << "|" << left << setw(22) << TransferRecord.DateTime;
		cout << left << setw(5) << "" << "|" << left << setw(5) << TransferRecord.SourceAccount;
		cout << left << setw(5) << "" << "|" << left << setw(5) << TransferRecord.DestinationAccoutn;
		cout << left << setw(5) << "" << "|" << left << setw(12) << TransferRecord.Amount;
		cout << left << setw(5) << "" << "|" << left << setw(12) << TransferRecord.SBalance;
		cout << left << setw(5) << "" << "|" << left << setw(12) << TransferRecord.DBalance;
		cout << left << setw(5) << "" << "|" << left << setw(5) << TransferRecord.User;

	}

public:
	static void ShowTransferLogScreen() {

		vector <clsBankClient::RegisterTransferLog> vRegisterTransferRecord = clsBankClient::GetRegisterTransferLogData();


		string Title = "Transfer Register List";
		string Subtitle = "(" + to_string(vRegisterTransferRecord.size()) + ") Transfer(s).";

		_DrawScreenHeader(Title, Subtitle);


		cout << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";
		cout << left << setw(5) << "" << "|" << left << setw(22) << "Date-Time";
		cout << left << setw(5) << "" << "|" << left << setw(5) << "S.Acc";
		cout << left << setw(5) << "" << "|" << left << setw(5) << "D.Acc";
		cout << left << setw(5) << "" << "|" << left << setw(12) << "Amount";
		cout << left << setw(5) << "" << "|" << left << setw(12) << "S.Balance";
		cout << left << setw(5) << "" << "|" << left << setw(12) << "D.Balance";
		cout << left << setw(5) << "" << "|" << left << setw(5) << "User";
		cout << endl << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";

		if (vRegisterTransferRecord.size() == 0) {
			cout << "\n\t\t\t\t\tNO TRANSFERS FOUND TO LIST.\n";
			cout << "\n---------------------------------------------------------------------------------------------------------\n";

		}
		else {
			for (clsBankClient::RegisterTransferLog TransferRecord : vRegisterTransferRecord) {
				_PrintTransferRecordLine(TransferRecord);
				cout << endl;
			}
		}
		cout << left << setw(5) << "" << "--------------------------------------------------------------------------------------------------------------\n";
	}
	
};

