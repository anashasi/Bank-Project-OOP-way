#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsString.h"
using namespace std;

class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line,string Seprateor="#//#") {
		vector <string> vCurrencyData = clsString::Split(Line, Seprateor);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency1, string Seprateor = "#//#") {
		string Line = "";
		Line = Currency1.Country() + Seprateor;
		Line += Currency1.CurrencyCode() + Seprateor;
		Line += Currency1.CurrencyName() + Seprateor;
		Line += to_string(Currency1.Rate()) ;

		return Line;
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile() {
		fstream MyFile;
		MyFile.open("CurrencyList.txt", ios::in);
		vector <clsCurrency> vCurrencyList;

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency c1 = _ConvertLineToCurrencyObject(Line);
				vCurrencyList.push_back(c1);
			}

			MyFile.close();
		}
		return vCurrencyList;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencyList) {
		fstream MyFile;
		MyFile.open("CurrencyList.txt", ios::out);

		if (MyFile.is_open()) {
			string Line;
			for(clsCurrency c1:vCurrencyList) {
				Line = _ConvertCurrencyObjectToLine(c1);
				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}


	void _Update() {
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}
		_SaveCurrencyDataToFile(_vCurrencys);

	}


	


public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	static clsCurrency GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static vector <clsCurrency> GetCurrencyList() {
		return _LoadCurrencyDataFromFile();
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	float Rate() {
		return _Rate;
	}

	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency FindByCode(string Code) {
		Code = clsString::UpperAllString(Code);
		fstream MyFile;
		MyFile.open("CurrencyList.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";
			while (getline(MyFile, Line)) {
				clsCurrency c1 = _ConvertLineToCurrencyObject(Line);
				if (c1.CurrencyCode() == Code) {
					MyFile.close();
					return c1;
				}
			}
			MyFile.close();
		}
	
		return GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("CurrencyList.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";
			while (getline(MyFile, Line)) {
				clsCurrency c1 = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(c1.Country()) == Country) {
					MyFile.close();
					return c1;
				}
			}
			MyFile.close();
		}

		return GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExistByCode(string CurrencyCode) {
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static bool IsCurrencyExistByCountry(string country) {
		clsCurrency Currency = clsCurrency::FindByCountry(country);
		return (!Currency.IsEmpty());
	}

};

