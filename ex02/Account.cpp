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
	std::cerr << "Index " << _accountIndex << " Account constructor called" << std::endl;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
	std::cerr << "Index " << _accountIndex << " Account destructor called" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";";

	_amount += deposit;
	std::cout << "amount:" << _amount << ";nb_deposits:" << ++_nbDeposits << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";";

	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount(void) const {
	return (_amount);
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
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
