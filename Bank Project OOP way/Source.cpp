#include <iostream>
#include "clsLoginScreen.h"
using namespace std;


int main() {

	while (true) {
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}

	system("pause");
	system("cls");
	return 0;
}