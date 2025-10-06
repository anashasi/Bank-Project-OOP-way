#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _Lastname;
	string _Email;
	string _Phone;
public:
	clsPerson(string FirstName,string LastName,string Email,string Phone){
		_FirstName = FirstName;
		_Lastname = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}

	string GetFirstName() {
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string LastNAme) {
		_Lastname = LastNAme;
	}

	string GetLastName() {
		return _Lastname;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	void SetEmail(string Email) {
		_Email = Email;
	}

	string GetEmail() {
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void SetPhone(string Phone) {
		_Phone = Phone;
	}

	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName() {
		return (_FirstName + " " + _Lastname);
	}
};

