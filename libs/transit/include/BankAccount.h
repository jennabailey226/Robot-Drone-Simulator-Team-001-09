#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include "IWalletDecorator.h"

/**
 * @class BankAccount
 * @brief Represents a bank account.
 */
class BankAccount : public IWalletDecorator {
 public:
  /**
   * @brief Bank accounts are created
   * @param name the name the account is under
   */
  BankAccount(std::string name) : IWalletDecorator(nullptr) {
    accountName = name;
  }

  /**
   * @brief Destructor.
   */
  ~BankAccount() {}

  /**
   * @brief BankAccounts do not have a position
   * @return none - bank accounts are non-physical entities.
   */
  Vector3 GetPosition() const { return noPos; }

  /**
   * @brief BankAccounts do not have direction
   * @return none - bank accounts are non-physical entities.
   */
  Vector3 GetDirection() const { return noPos; }

  /**
   * @brief BankAccounts do not have a destination
   * @return none - bank accounts are non-physical entities.
   */
  Vector3 GetDestination() const { return noPos; }

  /**
   * @brief Gets the details of the bank account.
   * @return The details of the bank account.
   */
  JsonObject GetDetails() const { return noDetails; }

  /**
   * @brief Gets the speed of the bank account (0).
   * @return 0 - bank accounts are not physical entities.
   */
  float GetSpeed() const { return 0; }

  /**
   * @brief Gets the availability of the bank account.
   * @return false - Bank accounts do not have availability.
   */
  bool GetAvailability() const { return false; }

  /**
   * @brief Get the Strategy Name (none)
   * @return Strategy name (none)
   */
  std::string GetStrategyName() const { return ""; }

  /**
   * @brief Get the account name of a bank account
   * @return the account name.
  */
  std::string GetAccountName() const { return accountName; }

  /**
   * @brief Get the balance of a bank account
   * @return The balance of the bank account
  */
  float GetBalance() { return balance; }

 private:
  std::string accountName;
  Vector3 noPos;
  JsonObject noDetails;
};

#endif
