#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyExchangMainScreen: protected clsScreen
{
private:
	enum enCurrencyExchangeMenueOptions {
		enListCurrencies = 1, enFindCurrency = 2,
		enUpdateRate = 3, enCurrenctCalculator = 4, enShowMainMenue = 5
	};

	static short  _ReadCurrencyExchangeMenueOption() {
		cout << setw(37) << left << "" << "\tChoose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenue() {
		cout << "Press any Key To Go Back To Currency Exchange Menue..........\n";
		system("pause>0");
		ShowCurrencyExchangemainScreen();
	}

	static void _ShowListCurrenciesScreen() {
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen() {
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen() {
		clsUpdateRateScreen::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen() {
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption) {
		switch (CurrencyExchangeMenueOption) {
		case enCurrencyExchangeMenueOptions::enListCurrencies: {
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeMenueOptions::enFindCurrency: {
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeMenueOptions::enUpdateRate: {
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeMenueOptions::enCurrenctCalculator: {
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeMenueOptions::enShowMainMenue: {

			break;
		}
		}
	}


public:
	static void ShowCurrencyExchangemainScreen() {

		system("cls");
		_DrawScreenHeader("Currency Exchange Screen");

		cout << left << setw(34) << "" << "=====================================================\n\n";
		cout << setw(34) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << left << setw(34) << "\n" << " =====================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t\t[5] Main Menue.\n";
		cout << left << setw(34) << "\n" << " =====================================================\n";
		_PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeMenueOption());
	}
};

