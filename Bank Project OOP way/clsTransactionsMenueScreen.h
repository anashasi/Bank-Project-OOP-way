#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include"clsInputValidate.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;
class clsTransactionsMenueScreen:protected clsScreen
{
private:
	enum enTransactionMenueOptions {
		enDeposit=1,enWithdraw=2,
		enShowTotalBalances=3, enTransfer=4,enTransferLog=5,enShowMainMenue=6
	};

	static short  _ReadTransactionMenuOption() {
		cout << setw(37) << left << "" << "\tChoose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToTransactionMenuScreen() {
		cout << "Press any Key To Go Back To Transaction Menue..........\n";
		system("pause>0");
		ShowTransactionsMenueScreen();
	}

	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionMenueOption(enTransactionMenueOptions TransactionMenueOption) {
		switch (TransactionMenueOption) {
			case enTransactionMenueOptions::enDeposit:{
				system("cls");
				_ShowDepositScreen();
				_GoBackToTransactionMenuScreen();
					break;
				}

			case enTransactionMenueOptions::enWithdraw: {
				system("cls");
				_ShowWithdrawScreen();
				_GoBackToTransactionMenuScreen();
				break;
			}

			case enTransactionMenueOptions::enShowTotalBalances: {
				system("cls");
				_ShowTotalBalancesScreen();
				_GoBackToTransactionMenuScreen();
				break;
			}
			
			case enTransactionMenueOptions::enTransfer: {
				system("cls");
				_ShowTransferScreen();
				_GoBackToTransactionMenuScreen();
				break;
			}

			case enTransactionMenueOptions::enTransferLog: {
				system("cls");
				_ShowTransferLogScreen();
				_GoBackToTransactionMenuScreen();
				break;
			}

			case enTransactionMenueOptions::enShowMainMenue: {
				
				break;
			}
		}
	}


public:
	static void ShowTransactionsMenueScreen() {
		if (!CheckAccessRihgts(clsUser::enPermission::enTransactionMenue)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("Transactions Menue");

		cout << left << setw(34) << "" << "=====================================================\n\n";
		cout << setw(34) << left << "" << "\t\t\tTransAction Menue\n";
		cout << left << setw(34) << "\n" << " =====================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t\t[3] Show Total Balances.\n";
		cout << setw(37) << left << "" << "\t\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t\t[6] Main Menue.\n";
		cout << left << setw(34) << "\n" << " =====================================================\n";
		_PerformTransactionMenueOption((enTransactionMenueOptions)_ReadTransactionMenuOption());
	}
};

