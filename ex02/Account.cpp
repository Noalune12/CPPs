#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
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

// annee mois jour _ heure minute seconde
// time get the time in second since 1970
// tm->tm_year year since 1900, need to add 1900 to get the real year.
// tm->tm_mon index of month so +1.

void	Account::_displayTimestamp(void)
{
	std::time_t now;
	std::time(&now);
	std::tm *timestamp = std::localtime(&now);

	std::cout << "[" << timestamp->tm_year + 1900 << std::flush;
	if (timestamp->tm_mon + 1 < 10)
		std::cout << "0" << timestamp->tm_mon + 1 << std::flush;
	else
		std::cout << timestamp->tm_mon + 1 << std::flush;
	if (timestamp->tm_mday < 10)
		std::cout << "0" << timestamp->tm_mday << std::flush;
	else
		std::cout << timestamp->tm_mday << std::flush;
	std::cout << "_" << std::flush;
	if (timestamp->tm_hour < 10)
		std::cout << "0" << timestamp->tm_hour << std::flush;
	else
		std::cout << timestamp->tm_hour << std::flush;
	if (timestamp->tm_min < 10)
		std::cout << "0" << timestamp->tm_min << std::flush;
	else
		std::cout << timestamp->tm_min << std::flush;
	if (timestamp->tm_sec < 10)
		std::cout << "0" << timestamp->tm_sec << std::flush;
	else
		std::cout << timestamp->tm_sec << std::flush;
	std::cout << "] " << std::flush;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_nbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit << ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_amount -= withdrawal;
	if (checkAmount() == 0)
	{
		_amount += withdrawal;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	_nbWithdrawals += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
		<< ";withdrawal:" << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	if (_amount < 0)
		return (0);
	return (1);
}
