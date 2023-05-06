#ifndef ROBOT_WALLET_DECORATOR_H_
#define ROBOT_WALLET_DECORATOR_H_

#include "Robot.h"
#include "IWalletDecorator.h"

class RobotWalletDecorator : public IWalletDecorator {
 public:
    /**
   * @brief Construct a new Robot Wallet Decorator object, initializes funds to $20
   *
   * @param entity the robot entity to decorate onto
   */
  RobotWalletDecorator(IEntity* entity) : IWalletDecorator(entity) {
    balance = Random(0, 50);
    std::cout << "Robot has $" << balance << " in his wallet" << std::endl;
    hasPaid = false;
    needsMoney = false;
  }

    /**
   * @brief Wallet Destructor
   */
  ~RobotWalletDecorator();
  
  /**
   * @brief Return whether or not a robot has paid for its trip
   * @return Boolean whether or not it has paid
  */
  bool GetHasPaid() { return hasPaid; }

/**
 * @brief Return whether or not a robot needs money from an ATMDrone
 * @return Boolean whether or not the robot needs money.
*/
  bool GetNeedsMoney() { return needsMoney; }

/**
 * @brief Set whether a robot has paid for its trip
 * @param update New boolean to set hasPaid to
*/
  void SetHasPaid(bool update) { hasPaid = update; } 

/**
 * @brief Set whether or not a robot needs money from an ATMDrone
 * @param update New boolean to set needsMoney to
*/
  void SetNeedsMoney(bool update) { needsMoney = update; }

 protected:
  bool hasPaid;
  bool needsMoney;

};

#endif
