#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;
class clsUpdateRateScreen:protected clsScreen
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

	static bool _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
			return true;
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
			return false;
		}
	}

public:
	static void ShowUpdateRateScreen() {
		_DrawScreenHeader("Update Currency Screen");

		string CurrencyCode;
		cout << "\nPlease Enter CurrencyCode: ";
		CurrencyCode = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		if (_ShowResults(Currency)) {
			char choice = 'n';
			cout << "Are you sure you want to update the rate of this currency? [Y/N] ";
			cin >> choice;

			if (choice == 'Y' || choice == 'y') {
				float NewRate = 0;
				cout << "\nUpdate Currency Rate \n";
				cout << "\n------------------------------\n";
				cout << "Enter New Rate : ";
				cin >> NewRate;
				Currency.UpdateRate(NewRate);
				_PrintCurrencyCard(Currency);
			}
		}

	}
};

