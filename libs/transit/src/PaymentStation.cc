#include "PaymentStation.h"

PaymentStation::PaymentStation(JsonObject &obj) : details(obj) {
    static std::vector<BankAccount*> bankAccounts;
    accounts = bankAccounts;
    if (bankAccounts.size() == 0) {
        AddAccount("National Bank");
        accounts.at(0)->deposit(10000); 
        //This is the national bank's account. Economy down bad.
    }
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};
    JsonArray dir(obj["direction"]);
    direction = {dir[0], dir[1], dir[2]};
    available = true;
}

void PaymentStation::AddAccount(std::string accountName) {
    for (auto account : accounts) {
        if (account->GetAccountName() == accountName) {
            std::cout << "Account name already taken" << std::endl;
            return;
        }
    }
    accounts.push_back(new BankAccount(accountName));
}

bool PaymentStation::Deposit(float amount, std::string accountName, IWalletDecorator* wallet) {
    for (auto account : accounts) {
        if (account->GetAccountName() == accountName) {
            if (wallet->withdraw(amount)) {
                account->deposit(amount*0.95);
                accounts.at(0)->deposit(amount*0.05); //ATM Fee
                std::cout << "$" << amount*.95 << " deposited into " << accountName << " account" << std::endl;
                std::cout << "ATM fee of 5% applied. National Bank balance is now $" << accounts.at(0)->GetBalance() << std::endl;
                return true;
            }
            else {
                std::cout << "Not enough money in wallet" << std::endl;
                return false;
            }
        }
    }
    std::cout << "No account found" << std::endl;
    return false;
}

bool PaymentStation::Withdraw(float amount, std::string accountName, IWalletDecorator* wallet) {
    for (auto account : accounts) {
        if (account->GetAccountName() == accountName) {
            if (account->withdraw(amount)) {
                wallet->deposit(amount*0.95);
                accounts.at(0)->deposit(amount*0.05); //ATM Fee
                std::cout << "$" << amount*.95 << " withdrawn from " << accountName << " account" << std::endl;
                std::cout << "ATM fee of 5% applied. National Bank balance is now $" << accounts.at(0)->GetBalance() << std::endl;
                return true;
            }
            else {
                std::cout << "Not enough money in bank account" << std::endl;
                return false;
            }
        }
    }
    std::cout << "No account found" << std::endl;
    return false;
}



