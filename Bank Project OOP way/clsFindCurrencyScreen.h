#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency c1) {
		cout << "\nCurrency Card :\n";
		cout << "\n------------------------------\n";
		cout << "\nCountry    : " << c1.Country();
		cout << "\nCode       : " << c1.CurrencyCode();
		cout << "\nName       : " << c1.CurrencyName();
		cout << "\nRate/($1)  = " << c1.Rate();
		cout << "\n------------------------------\n\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}


public:
	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("Find Currency");
		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;

		cin >> Answer;

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}
	}
};

