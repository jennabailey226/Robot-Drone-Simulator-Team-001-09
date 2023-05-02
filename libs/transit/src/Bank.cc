#include "Bank.h"

void Bank::AddAccount(std::string accountName) {
    accounts.push_back(new BankAccountWalletDecorator(new BankAccount(accountName)));
}

BankAccountWalletDecorator& Bank::AccessAccount(std::string accountName) {
    for (auto account : accounts) {
        if (account->getName() ==  accountName) {
            return account;
        }
    }
    std::cout << "No account found" << std::endl;
    return nullptr;
}