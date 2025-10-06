#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <string>
#include "clsDate.h"
#include "Global.h"
using namespace std;

class clsBankClient:public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode=2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string line, string seprateor="#//#") {
		vector <string> vClientData;
		vClientData = clsString::Split(line, seprateor);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	


	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient>  _LoadDataFromFile() {
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);

		if(MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();

		}
		return vClients;
	}

	string _ConvertClientObjectToLine(clsBankClient Client,string seprateor="#//#") {
		string Line = "";
		Line = Client.FirstName + seprateor;
		
		Line += Client.LastName + seprateor;

		Line += Client.Email + seprateor;

		Line += Client.Phone + seprateor;

		Line += Client.GetAccountNumber() + seprateor;

		Line += Client.PinCode + seprateor;

		Line += to_string(Client.AccountBalance);

		return Line;
	}
	void _SaveCleintsDataToFile(vector <clsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Client.txt", ios::out);

		if (MyFile.is_open()) {
			string Line = "";
			for (clsBankClient Client : vClients) {
				if (Client.MarkedForDeleted() == false) {
					Line = _ConvertClientObjectToLine(Client);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector <clsBankClient> vClients;
		vClients = _LoadDataFromFile();

		for (clsBankClient& Client : vClients) {
			if (this->_AccountNumber == Client.GetAccountNumber()) {
				Client = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(vClients);
	}

	void _AddDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Client.txt", ios::out | ios::app);

		if (MyFile.is_open()) {
			MyFile << DataLine << endl;
		}
		MyFile.close();
	}

	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}


	string _GetTranferLine(clsBankClient ToCLient2,float Amount, string Sepratetor="#//#") {
		string Line = clsDate::GetSystemDateTimeString() + Sepratetor;
		Line += _AccountNumber + Sepratetor;
		Line += ToCLient2.GetAccountNumber() + Sepratetor;
		Line += to_string(Amount) + Sepratetor;
		Line += to_string(_AccountBalance) + Sepratetor;
		Line += to_string(ToCLient2.AccountBalance) + Sepratetor;
		Line += CurrentUser.UserName;
		return Line;
	}

	void _SaveTransferLog(clsBankClient ToClient2, float Amount) {
		string Line = _GetTranferLine(ToClient2, Amount);
		fstream MyFile;
		MyFile.open("Transfer.txt", ios::out | ios::app);

		if (MyFile.is_open()) {
			MyFile << Line << endl;
		}
		MyFile.close();
	}

	struct RegisterTransferLog;

	static RegisterTransferLog _ConvertTransferLineToRecord(string Line, string spratetor = "#//#") {
		vector <string> vTransferData;
		vTransferData = clsString::Split(Line, spratetor);

		RegisterTransferLog TransferRecord;
		TransferRecord.DateTime = vTransferData[0];
		TransferRecord.SourceAccount = vTransferData[1];
		TransferRecord.DestinationAccoutn = vTransferData[2];
		TransferRecord.Amount = vTransferData[3];
		TransferRecord.SBalance = vTransferData[4];
		TransferRecord.DBalance = vTransferData[5];
		TransferRecord.User = vTransferData[6];
		
		return TransferRecord;
	}

public:
	clsBankClient(enMode Mode,string FirstName,string LastName,string Email,string Phone,string AccountNumber,string PicnCode,float AccountBalance)
		:clsPerson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PicnCode;
		_AccountBalance = AccountBalance;
	}

	struct RegisterTransferLog {
		string DateTime="";
		string SourceAccount="";
		string DestinationAccoutn = "";
		string Amount = "";
		string SBalance = "";
		string DBalance = "";
		string User = "";
	};

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string GetAccountNumber() {
		return _AccountNumber;
	}
	
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string GetPinCode() {
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance() {
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	bool MarkedForDeleted() {
		return _MarkedForDelete;
	}



	static clsBankClient Find(string AccountNumber) {
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
			  
				clsBankClient Client = _ConvertLineToClientObject(line);
				if (Client.GetAccountNumber() == AccountNumber) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();

	 }


	static clsBankClient Find(string AccountNumber,string PinCode) {
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {

				clsBankClient Client = _ConvertLineToClientObject(line);
				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode==PinCode) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();

	}

	static bool IsClientExist(string Accountnumber) {
		clsBankClient Client = clsBankClient::Find(Accountnumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults{ svFaildEmptyObject=0, svSucceeded=1, svFaildAccountNumberExists=2};

	 enSaveResults Save() {
		 switch (_Mode)
		 {
		 case clsBankClient::EmptyMode: {
			 if (IsEmpty())
			 {
				 return enSaveResults::svFaildEmptyObject;
			 }
			 break;
		 }
			 
		 case clsBankClient::UpdateMode: {
			 _Update();
			 return enSaveResults::svSucceeded;
			 break;
		 }
			 
		 case clsBankClient::AddNewMode: {

			 if (clsBankClient::IsClientExist(_AccountNumber)) {
				 return enSaveResults::svFaildAccountNumberExists;
			}
			 
			 _AddNew();
			 _Mode = enMode::UpdateMode;
			 return enSaveResults::svSucceeded;
			 break;
		 }
			
		 }
	}

	 static clsBankClient GetAddNewClientObject(string AccountNumber) {
		 return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	 bool Delete() {
		 vector <clsBankClient> vClients;
		 vClients = _LoadDataFromFile();

		 for (clsBankClient& Client : vClients) {
			 if (Client._AccountNumber == _AccountNumber) {
				 Client._MarkedForDelete = true;
				 break;
			 }
		 }
		 _SaveCleintsDataToFile(vClients);
		 *this = _GetEmptyClientObject();
		 return true;
	 }

	static vector <clsBankClient> GetClientList() {
		 return _LoadDataFromFile();
	 }

	static double GetTotalBalances() {
		vector <clsBankClient> vClients = _LoadDataFromFile();
		double TotalBalances = 0;
		for (clsBankClient Client : vClients) {
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount) {
		if (Amount > _AccountBalance)
			return false;
		else {
			_AccountBalance -= Amount;
			Save();
		}
		return true;
	}

	bool Transfer(clsBankClient &ToCLient2, float Amount) {
		if (_AccountBalance < Amount)
			return false;
		else {
			Withdraw(Amount);
			ToCLient2.Deposit(Amount);
			_SaveTransferLog(ToCLient2, Amount);
			return true;
		}
	}

	static vector <RegisterTransferLog> GetRegisterTransferLogData() {
		vector <RegisterTransferLog> vTransferData;
		fstream MyFile;
		MyFile.open("Transfer.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";
			RegisterTransferLog TransferDataRecord;
			while (getline(MyFile, Line)) {
				TransferDataRecord = _ConvertTransferLineToRecord(Line);
				vTransferData.push_back(TransferDataRecord);
			}
			MyFile.close();
		}
		return vTransferData;
	}
};

