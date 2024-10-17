#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:"
		<< Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	std::cerr << "Index " << this->_accountIndex << " Account constructor called" << std::endl;
	this->_totalAmount += this->_amount;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void) {
	std::cerr << "Index " << this->_accountIndex << " Account destructor called" << std::endl;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";";

	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";nb_deposits:" << ++this->_nbDeposits << std::endl;

	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";";

	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;

	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount(void) const {
	return (this->_amount);
}

void Account::displayStatus(void) const {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {

	time_t time;
	std::time(&time);

	char timestamp[16];
	std::strftime(timestamp, 16, "%Y%m%d_%H%M%S", std::localtime(&time));
	std::cout << "[" << timestamp << "] ";
}
