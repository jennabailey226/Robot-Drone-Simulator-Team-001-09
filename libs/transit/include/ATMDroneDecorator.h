#ifndef ATM_DRONE_DECORATOR_H_
#define ATM_DRONE_DECORATOR_H_

#include "ATMDrone.h"
#include "IWalletDecorator.h"

class ATMDroneDecorator : public IWalletDecorator {
 public:
 /**
   * @brief Construct a new ATM Drone Wallet Decorator object
   *
   * @param entity the ATM Drone entity to decorate onto
   */
  ATMDroneDecorator(IEntity* entity) : IWalletDecorator(entity) {}
  
  /**
   * @brief Wallet Destructor
  */
  ~ATMDroneDecorator() {}

  /**
   * @brief Updates the entity's position in the physical system, with added functionality from Wallet Decorator.
   * @param dt The time step of the update.
   * @param scheduler The list of all entities in the system.
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

};

#endif