#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <string>
#include "clsDate.h"
using namespace std;
class clsUser : public clsPerson
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;

	bool _MarkedForDelete = false;

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string line, string seprateor = "#//#") {
		vector <string> vLoginRegisterRecord;
		vLoginRegisterRecord = clsString::Split(line, seprateor);

		stLoginRegisterRecord LoginRegisterRecord;
		LoginRegisterRecord.DateTime = vLoginRegisterRecord[0];
		LoginRegisterRecord.username = vLoginRegisterRecord[1];
		LoginRegisterRecord.password = clsString::DecryptString(vLoginRegisterRecord[2],3);
		LoginRegisterRecord.permission = vLoginRegisterRecord[3];

		return LoginRegisterRecord;
	}

	static clsUser _ConvertLineToUserObject(string Line,string sepratetor="#//#") {
		vector <string> vUsersData;
		vUsersData = clsString::Split(Line, sepratetor);


		vUsersData[5]=clsString::DecryptString(vUsersData[5],3);

		return clsUser(enMode::UpdateMode, vUsersData[0], vUsersData[1], vUsersData[2],
			vUsersData[3], vUsersData[4], vUsersData[5], stoi(vUsersData[6]));

	}

	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsUser> _LoadUsersDataFromFile() {
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";
			while (getline(MyFile,Line)) {
				clsUser User = clsUser::_ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}

	string _ConvertUserObjectToLine(clsUser User, string sepratetor = "#//#") {
		string Line = "";

		Line += User.FirstName + sepratetor;
		Line += User.LastName + sepratetor;
		Line += User.Email + sepratetor;
		Line += User.Phone + sepratetor;
		Line += User.UserName + sepratetor;
		Line += clsString::EncryptString (User.Password ,3)+ sepratetor;
		Line += to_string(User.GetPermission());
		return Line;
	}

	void _SaveUsersDataToFile(vector <clsUser> vUsers) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open()) {
			string Line = "";
			for (clsUser U : vUsers) {
				if (U.MarkedForDeleted() == false) {
					Line = _ConvertUserObjectToLine(U);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector <clsUser> vUsers;
		vUsers = _LoadUsersDataFromFile();

		for (clsUser User : vUsers) {
			if (this->UserName == User.GetUserName()) {
				User = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	 string _GetRegisteredUserData(string sepratetor = "#//#") {
		string s = "";
		s = clsDate::GetSystemDateTimeString() + sepratetor;
		s += _UserName + sepratetor;
		s += clsString::EncryptString( _Password,3 )+ sepratetor;
		s += to_string(_Permission);
		return s;
	}

public:

	enum enPermission {
		enAll=-1,enListClients=1,enAddNewClient=2,enDeleteClient=4,enUpdateClient=8,
		enFindClient=16,enTransactionMenue=32,enManageUsersMenue=64,enLoginRegister=128
	};

	struct stLoginRegisterRecord {
		string DateTime = "";
		string username = "";
		string password = "";
		string permission = "";
	};

	clsUser(enMode Mode,string FirstName,string LastName,string Email,string Phone,string UserNmae,string Password,int permission):
	clsPerson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		_UserName = UserNmae;
		_Password = Password;
		_Permission = permission;
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted() {
		return _MarkedForDelete;
	}

	string GetUserName() {
		return _UserName;
	}

	void SetUserName(string UserName) {
		_UserName = UserName;
	}

	_declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	string GetPassword() {
		return _Password;
	}

	void SetPassword(string Password) {
		_Password = Password;
	}

	_declspec(property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermission() {
		return _Permission;
	}

	void SetPermission(int Permission) {
		_Permission = Permission;
	}

	_declspec(property(get = GetPermission, put = SetPermission)) int Permission;

	static clsUser Find(string Username) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {

				clsUser User = _ConvertLineToUserObject(line);
				if (User.GetUserName() == Username) {
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string Username,string Password) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {

				clsUser User = _ConvertLineToUserObject(line);
				if (User.GetUserName() == Username && User.GetPassword()==Password) {
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName) {
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	enSaveResults Save() {
		switch (_Mode)
		{
			case enMode::EmptyMode: {
				if (IsEmpty())
				return enSaveResults::svFaildEmptyObject;
				break;
			}

			case enMode::UpdateMode: {
				_Update();
				return enSaveResults::svSucceeded;
				break;
			}

			case enMode::AddNewMode: {
				if (clsUser::IsUserExist(_UserName))
					return enSaveResults::svFaildUserExists;
				
				else {
					_AddNew();
					_Mode = enMode::AddNewMode;
					return svSucceeded;
				}

				break;
			}

	    }
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U._UserName == _UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}


	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	 bool CheckAccessPermission(enPermission Permission) {
		 if (this->_Permission == enPermission::enAll)
			 return true;
		 if ((Permission & this->_Permission)== Permission)
			 return true;
		 else
			 return false;

	}

	 void RegisterLogin() {
		 string Line = _GetRegisteredUserData();
		 fstream  MyFile;
		 MyFile.open("RegisterFile.txt", ios::out | ios::app);
		 if (MyFile.is_open()) {
			 MyFile <<Line << endl;
		 }
		 MyFile.close();
	 }

	


	 static vector <stLoginRegisterRecord> GetLoginRegisterDataFromFile() {
		 vector <stLoginRegisterRecord> vLoginsRegisterRecord;
		 fstream MyFile;
		 MyFile.open("RegisterFile.txt", ios::in);

		 if (MyFile.is_open()) {
			 string Line;
			 stLoginRegisterRecord LoginRegisterRecord;
			 while (getline(MyFile, Line)) {
				 LoginRegisterRecord = _ConvertLineToLoginRegisterRecord(Line);
				 vLoginsRegisterRecord.push_back(LoginRegisterRecord);
			 }
			 MyFile.close();
		 }
		 return vLoginsRegisterRecord;
	 }
};

