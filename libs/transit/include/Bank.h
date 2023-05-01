#ifndef BANK_H_
#define BANK_H_

#include "PaymentStation.h"

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
  Bank(JsonObject& obj);

  /**
   * @brief Destructor.
   */
  ~Bank();

  void AddAccount(std::string name, std::string password);

  void DeleteAccount()

 private:
  std::vector<BankAccount> accounts;
};

#endif