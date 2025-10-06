#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen
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


	static clsCurrency ReadCurrency(string message) {
		cout << endl<<message;
		string Code = "";
		Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExistByCode(Code)) {
			cout << "\nCurrency Not foud, enter another code : ";
			Code = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		return Currency;
	}

	static float _ExchangeCurrency1toUsd(clsCurrency Currency1,clsCurrency USD,float Amount) {
		if (Currency1.Rate() > USD.Rate())
			return (Amount / Currency1.Rate());
		else
			return (Amount * Currency1.Rate());
	}
	 
	static float _ExchangeUSDtoCurrency2(clsCurrency USD, clsCurrency Currency2, float Amount) {
			return (Amount * Currency2.Rate());
	}



public:
	static void ShowCurrencyCalculatorScreen() {
		char choice = 'y';

		while (choice == 'Y' || choice == 'y') {
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency Currency1 = ReadCurrency("Please enter Currency1 code: ");
			clsCurrency Currency2 = ReadCurrency("Please enter Currency2 code: ");

			float Amount = 0;
			cout << "\nPlease Enter Amount to exchange : ";
			cin>> Amount;

			if (Currency2.CurrencyCode() == "USD") {
				cout << "\nConvert From \n";
				_PrintCurrencyCard(Currency1);
				cout << "\n" << Amount << " " + Currency1.CurrencyCode() + " = " << _ExchangeCurrency1toUsd(Currency1, Currency2, Amount) << " USD" << endl;

			}
			else if (Currency1.CurrencyCode() == "USD") {

				cout << "\nConverting From USD TO:  \n";
				_PrintCurrencyCard(Currency2);
				cout << "\n" << Amount << " USD = " << _ExchangeUSDtoCurrency2(Currency1, Currency2,Amount) << " " + Currency2.CurrencyCode() << endl;
			
			 }
			else {
				cout << "\nConvert From \n";
				_PrintCurrencyCard(Currency1);
				float USDAmount = _ExchangeCurrency1toUsd(Currency1, Currency2, Amount);
				cout << "\n" << Amount << " " + Currency1.CurrencyCode() + " = " << USDAmount << " USD"<< endl;

				cout << "\nConverting From USD TO:  \n";
				_PrintCurrencyCard(Currency2);
				cout << "\n" << Amount << " " + Currency1.CurrencyCode() + " = " << _ExchangeUSDtoCurrency2(Currency1, Currency2, USDAmount) << " " + Currency2.CurrencyCode() << endl;
			}

			cout << "\nDo you want to perform another calculation ? [Y/N] ";
			cin >> choice;
		}
	}
};

