#include "PaymentStation.h"

PaymentStation::PaymentStation(JsonObject &obj) : details(obj) {
    static std::vector<BankAccount*> bankAccounts;
    accounts = bankAccounts;
    if (bankAccounts.size() == 0) {
        bankAccounts.push_back(new BankAccount("bank"));
        bankAccounts.at(0)->deposit(5000000000); 
        //The world's largest bank has about $4 billion. Our bank has more.
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
                account->deposit(amount);
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
                wallet->deposit(amount);
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

// BankAccount* PaymentStation::AccessAccount(std::string accountName) {
//     for (auto account : accounts) {
//         if (account->GetAccountName() == accountName) {
//             return account;
//         }
//     }
//     std::cout << "No account found" << std::endl;
//     return nullptr;
// }



