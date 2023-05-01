#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include "IEntity.h"

/**
 * @class BankAccount
 * @brief Represents a bank account.
 */
class BankAccount : public IEntity {
 public:
  /**
   * @brief Bank accounts are created
   * @param name the name the account is under
   * @param pw the password to access the account
   */
  BankAccount(std::string name, std::string pw) {
    accountName = name;
    password = pw;
  }

  /**
   * @brief Destructor.
   */
  ~BankAccount();

  /**
   * @brief BankAccounts do not have a position
   * @return none - bank accounts are non-physical entities.
   */
  Vector3 GetPosition() const { return none; }

  /**
   * @brief BankAccounts do not have direction
   * @return none - bank accounts are non-physical entities.
   */
  Vector3 GetDirection() const { return none; }

  /**
   * @brief BankAccounts do not have a destination
   * @return none - bank accounts are non-physical entities.
   */
  Vector3 GetDestination() const { return none; }

  /**
   * @brief Gets the details of the bank account.
   * @return The details of the bank account.
   */
  JsonObject GetDetails() const { return none; }

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

  bool CheckPassword(std::string pw) { return pw == password; }

 private:
  std::string password;
  std::string accountName;
};

#endif