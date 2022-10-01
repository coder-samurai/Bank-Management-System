// libraries
#include <iostream>
#include <time.h>


class Atm {

	public:

		// random amount of money
		int amount = rand() % 1000;

		// func to show the menu
		void showMenu() {
			std::cout << "**************************" << std::endl;
			std::cout << "***** Welcome to ATM *****" << std::endl;
			std::cout << "**************************" << std::endl;
			std::cout << "**** 1. Check Balance ****" << std::endl;
			std::cout << "**** 2. Deposit       ****" << std::endl;
			std::cout << "**** 3. Withdraw      ****" << std::endl;
			std::cout << "**** 4. Exit          ****" << std::endl;
			std::cout << "**************************" << std::endl;
			std::cout << "**************************" << std::endl;
		}

		// func to show the balance
		void showBalance() {

			// show the balance
			std::cout << "\n[!] Your balance is: $" << amount << std::endl;
		}

		// func to deposit money
		void Deposit() {

			// get the amount to deposit
			int amountDeposited;
			std::cout << "\n[?] Enter the amount to deposit: $";
			std::cin >> amountDeposited;

			// add the amount to the balance
			amount += amountDeposited;

			// show the balance
			std::cout << "\n[!] Your balance is: $" << amount << std::endl;
		}

		// func to withdraw money
		void Withdraw() {

			// get the amount to withdraw
			int amountWithdrawn;
			std::cout << "\n[?] Enter the amount to withdraw: $";
			std::cin >> amountWithdrawn;

			// check if the amount is less than the balance
			if (amountWithdrawn > amount) {
				std::cout << "\n[!] Insufficient funds!" << std::endl;
			}
			else {
				// subtract the amount from the balance
				amount -= amountWithdrawn;

				// show the balance
				std::cout << "\n[!] Your balance is: $" << amount << std::endl;
			}
		}

};


int main() {
	srand(time(NULL));

	// variables
	int menuOption;
	bool running = true;

	// objects
	Atm bms;
	bms.showMenu();

	// while input
	while (running) {

		// input menu option
		std::cout << "\n[+] Enter your option: ";
		std::cin >> menuOption;

		// switch statement
		switch (menuOption) {
			case 1:
				bms.showBalance();
				break;
			case 2:
				bms.Deposit();
				break;
			case 3:
				bms.Withdraw();
				break;
			case 4:
				std::cout << "Exit" << std::endl;
				running = false;
				break;
		}
	}
}