#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::cout << "Display timestamp" << std::endl;
}

void	Account::displayAccountsInfos(void) {
	std::cout << "Display accounts infos" << std::endl;
}

void Account::displayStatus(void) const {
	std::cout << "Display status" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	std::cout << "Make deposit : " << deposit << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	std::cout << "Make withdrawal : " << withdrawal << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	std::cout << "Check amount : " << std::endl;
	return (0);
}
