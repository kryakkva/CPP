#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
	Account::_totalAmount += this->_amount;
}

Account::Account(void)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
	// Account::_totalAmount += this->_amount;
}

Account::~Account()
{
	Account::_displayTimestamp();
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed\n";
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout	<< ";amount:" << this->_amount
				<< ";nb_deposits:" << ++this->_nbDeposits
				<< std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount;
	if (this->checkAmount() - withdrawal < 0)
		std::cout << ";withdrawal:refused\n";
	else {
		this->_amount -= withdrawal;
		std::cout	<< ";withdrawal:" << withdrawal
					<< ";amount:" << this->_amount
					<< ";nb_withdrawals:" << ++this->_nbWithdrawals
					<< std::endl;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -=withdrawal;
	}

	return (true);
}

void	Account::_displayTimestamp( void )
{
	std::time_t result = std::time(NULL);
	std::tm *time = std::localtime(&result);
	std::cout	<< std::setfill('0') << "[" << (time->tm_year + 1900)
				<< std::setw(2) << (time->tm_mon + 1) 
				<< std::setw(2) << time->tm_mday << "_"
				<< std::setw(2) << time->tm_hour
				<< std::setw(2) << time->tm_min
				<< std::setw(2) << time->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int	Account::getNbAccounts( void ) {return (Account::_nbAccounts);}
int	Account::getTotalAmount( void ) {return (Account::_totalAmount);}
int	Account::getNbDeposits( void ) {return (Account::_totalNbDeposits);}
int	Account::getNbWithdrawals( void ){return (Account::_totalNbWithdrawals);}

