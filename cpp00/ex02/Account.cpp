/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:42:20 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 10:41:42 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account	(int	initial_deposit)
{
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	this->_accountIndex = getNbAccounts();
	_nbAccounts += 1;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount + deposit << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	this->_amount += deposit;
	this->_nbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->_amount - withdrawal >= 0)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount - withdrawal << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals + 1;
		std::cout << std::endl;
		_totalNbWithdrawals += 1;
		_nbWithdrawals += 1;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

int	Account::checkAmount (void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t time;
	std::tm		*informations;

	time = std::time(NULL);
	informations = std::localtime(&time);
	std::cout << "[";
	std::cout << informations->tm_year + 1900;
	if (informations->tm_mon < 10)
		std::cout << "0";
	std::cout << informations->tm_mon + 1;
	if (informations->tm_mday < 10)
		std::cout << "0";
	std::cout << informations->tm_mday << "_";
	if (informations->tm_hour < 10)
		std::cout << "0";
	std::cout << informations->tm_hour;
	if (informations->tm_min < 10)
		std::cout << "0";
	std::cout << informations->tm_min;
	if (informations->tm_sec < 10)
		std::cout << "0";
	std::cout << informations->tm_sec << "] ";
}
