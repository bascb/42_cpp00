/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:39:21 by bcastelo          #+#    #+#             */
/*   Updated: 2024/02/04 14:06:05 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

std::string	get_filename(void);

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);	
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::fstream	fs;
	
	_displayTimestamp();
	fs.open(get_filename().c_str(), std::fstream::app);
	fs << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	fs.close();
}

Account::Account( int initial_deposit )
{
	static int		index;
	std::fstream	fs;

	_accountIndex = index++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_nbAccounts++;
	_displayTimestamp();
	fs.open(get_filename().c_str(), std::fstream::app);
	fs << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	fs.close();
}

Account::~Account( void )
{
	std::fstream	fs;
	
	_displayTimestamp();
	fs.open(get_filename().c_str(), std::fstream::app);
	fs << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	fs.close();
}

void	Account::makeDeposit( int deposit )
{
	std::fstream	fs;
	
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	fs.open(get_filename().c_str(), std::fstream::app);
	fs << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	fs.close();
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::fstream	fs;
	
	_displayTimestamp();
	fs.open(get_filename().c_str(), std::fstream::app);
	if (_amount - withdrawal < 0)
	{
		fs << "index:" << _accountIndex << ";p_amount:" << _amount  << ";withdrawal:refused"  << std::endl;
		fs.close();
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	fs << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" <<  withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	fs.close();
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	std::fstream	fs;
	
	_displayTimestamp();
	fs.open(get_filename().c_str(), std::fstream::app);
	fs << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
	fs.close();
}

void	Account::_displayTimestamp( void )
{
	std::fstream	fs;
	std::time_t		t = std::time(0);
    std::tm*		now = std::localtime(&t);
	
	fs.open(get_filename().c_str(), std::fstream::app);
	fs << "[" << now->tm_year + 1900;
	if (now->tm_mon + 1 < 10)
		fs << "0" << now->tm_mon + 1;
	else
		fs << now->tm_mon + 1;
	if (now->tm_mday < 10)
		fs << "0" << now->tm_mday;
	else
		fs << now->tm_mday;
	fs << "_";
	if (now->tm_hour < 10)
		fs << "0" << now->tm_hour;
	else
		fs << now->tm_hour;
	if (now->tm_min < 10)
		fs << "0" << now->tm_min;
	else
		fs << now->tm_min;
	if (now->tm_sec < 10)
		fs << "0" << now->tm_sec;
	else
		fs << now->tm_sec;
	fs << "] ";
	fs.close();
}

std::string	get_filename(void)
{
	std::stringstream	filename;
	std::string			file_str;
	
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	filename << now->tm_year + 1900;
	if (now->tm_mon + 1 < 10)
		filename << "0" << now->tm_mon + 1;
	else
		filename << now->tm_mon + 1;
	if (now->tm_mday < 10)
		filename << "0" << now->tm_mday;
	else
		filename << now->tm_mday;
	filename << "_";
	if (now->tm_hour < 10)
		filename << "0" << now->tm_hour;
	else
		filename << now->tm_hour;
	if (now->tm_min < 10)
		filename << "0" << now->tm_min;
	else
		filename << now->tm_min;
	if (now->tm_sec < 10)
		filename << "0" << now->tm_sec;
	else
		filename << now->tm_sec;
	
	filename << ".log";
	file_str = filename.str();
	return (file_str);
}
