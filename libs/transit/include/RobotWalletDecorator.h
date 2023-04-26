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
  RobotWalletDecorator(IEntity* entity);

    /**
   * @brief Wallet Destructor
   */
  ~RobotWalletDecorator();

    /**
   * @brief Updates the entity's position in the physical system, with added functionality from Wallet Decorator.
   * @param dt The time step of the update.
   * @param scheduler The list of all entities in the system.
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler);

};

#endif
