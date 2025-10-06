#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;
class clsListCurrenciesScreen:protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency) {
		cout << left << setw(4) << "" << "|" << left << setw(30) << Currency.Country();
		cout << left << setw(4) << "" << "|" << left << setw(8) << Currency.CurrencyCode();
		cout << left << setw(4) << "" << "|" << left << setw(40) << Currency.CurrencyName();
		cout << left << setw(4) << "" << "|" << left << setw(10) << Currency.Rate();

	}


public:
	static void ShowListCurrenciesScreen() {

		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrencyList();

		string Title = "Currency List Screen";
		string SubTitle ="Currency List (" + to_string(vCurrencies.size())+ ") Currencies.";
		_DrawScreenHeader(Title, SubTitle);

		cout << left << setw(5) << "\n" << "---------------------------------------------------------------------------------------------------------\n";
		cout << left << setw(4) << "" << "|" << left << setw(30) << "Country";
		cout << left << setw(4) << "" << "|" << left << setw(8) << "Code";
		cout << left << setw(4) << "" << "|" << left << setw(40) << "Name";
		cout << left << setw(4) << "" << "|" << left << setw(10) << "Rate/(1$)";
		cout << left << setw(5) << "\n" << "---------------------------------------------------------------------------------------------------------\n";
		
	
			for (clsCurrency Currency : vCurrencies) {
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

		
		cout << left << setw(4) << "" << "---------------------------------------------------------------------------------------------------------\n";
	}
};

