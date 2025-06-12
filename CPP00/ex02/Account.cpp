/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:20:33 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/29 15:08:58 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Account.hpp"

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

void	Account::_displayTimestamp(void) {
	char	timestamp_final[19];
	std::time_t now;
	std::time(&now);
	std::tm *timestamp = std::localtime(&now);
	std::strftime(timestamp_final, sizeof(timestamp_final), "[%Y%m%d_%H%M%S] ", timestamp);
	std::cout << timestamp_final << std::flush;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_nbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit << ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
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

int		Account::checkAmount(void) const {
	if (_amount < 0)
		return (0);
	return (1);
}
