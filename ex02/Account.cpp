#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit) {
	_accountIndex = 0;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts = 0;
	_totalAmount = initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "Account created" << std::endl;
}

Account::~Account(void) {
	std::cout << "Account destructed" << std::endl;
}
