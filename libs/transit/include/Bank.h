#ifndef BANK_H_
#define BANK_H_

#include "PaymentStation.h"
#include "BankAccountWalletDecorator.h"

/**
 * @class Bank
 * @brief Represents a bank in a physical system. This is also a type of payment station.
 */
class Bank : public PaymentStation {
 public:
  /**
   * @brief Banks are created
   * @param obj JSON object containing the Bank's information
   */
  Bank(JsonObject& obj) : PaymentStation(obj) { bank = this; }

  /**
   * @brief Destructor.
   */
  ~Bank() {}

  void AddAccount(std::string accountName);

  BankAccountWalletDecorator& AccessAccount(std::string accountName);

 private:
  std::vector<BankAccountWalletDecorator&> accounts;
};

#endif