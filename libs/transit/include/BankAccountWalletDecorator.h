#ifndef BANKACCOUNT_WALLET_DECORATOR_H_
#define BANKACCOUNT_WALLET_DECORATOR_H_

#include "IWalletDecorator.h"
#include "BankAccount.h"

class BankAccountWalletDecorator : public IWalletDecorator {
 public:
 /**
   * @brief Construct a new Bank Account Wallet Decorator object
   *
   * @param entity the BankAccount entity to decorate onto
   */
  BankAccountWalletDecorator(IEntity* entity) : IWalletDecorator(entity) {};

    /**
   * @brief Wallet Destructor
   */
  ~BankAccountWalletDecorator();
};

#endif