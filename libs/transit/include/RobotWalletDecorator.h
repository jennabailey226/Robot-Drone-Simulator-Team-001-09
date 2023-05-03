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
    balance = 20;
    hasPaid = false;
    //entity is created in SimulationModel.cc and wrapped in wallet decorator in RobotFactory.cc
  };

    /**
   * @brief Wallet Destructor
   */
  ~RobotWalletDecorator();
  
  bool getHasPaid() { return hasPaid; }

  bool getNeedsMoney() { return needsMoney; }

  void setHasPaid(bool update) { hasPaid = update; } 

  void setNeedsMoney(bool update) { needsMoney = update; }

  //std::string GetStrategyName() const { return entity->GetStrategyName(); }

 protected:
  bool hasPaid;
  bool needsMoney;

};

#endif
