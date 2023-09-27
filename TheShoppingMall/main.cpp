#define _CRT_SECURE_NO_WARNINGS
#include "ShoppingMallManager.h"
#include <iostream>
using namespace std;


int main() {
	bool loop = true;
	ShoppingMallManager* manager = ShoppingMallManager::getManagerInstance();
	do {
		try {
			cout << "--------------------------------" << endl;
			showMenu();
			int selection = getIntFromUser("your selection", 1, 8);
			switch (selection) {
			case 1:
				manager->createStore();
				break;
			case 2:
				manager->createEmployee();
				break;
			case 3:
				manager->createClient();
				break;
			case 4:
				manager->showMallEmployees();
				break;
			case 5:
				manager->showMallStores();
				break;
			case 6:
				manager->showMall();
				break;
			case 7:
				manager->selectStoreMenu();
				break;
			case 8:
				loop = false;
				manager->releaseManagerInstance();
				cout << "Have a nice day." << endl;
				break;
			}
		}
		catch (MallExceptions& e) {
			e.show();
		}
	} while (loop);
	return 0;
}