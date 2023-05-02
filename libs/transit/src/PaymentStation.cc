#include "PaymentStation.h"

PaymentStation::PaymentStation(JsonObject &obj) : details(obj) {
    static std::vector<BankAccount*> bankAccounts;
    accounts = bankAccounts;
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};
    JsonArray dir(obj["direction"]);
    direction = {dir[0], dir[1], dir[2]};
    available = true;
}

void PaymentStation::AddAccount(std::string accountName) {
    accounts.push_back(new BankAccount(accountName));
}

BankAccount* PaymentStation::AccessAccount(std::string accountName) {
    for (auto account : accounts) {
        if (account->GetAccountName() ==  accountName) {
            return account;
        }
    }
    std::cout << "No account found" << std::endl;
    return nullptr;
}

