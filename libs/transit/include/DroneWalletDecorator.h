#ifndef DRONE_WALLET_DECORATOR_H_
#define DRONE_WALLET_DECORATOR_H_

#include "Drone.h"
#include "IWalletDecorator.h"

class DroneWalletDecorator : public IWalletDecorator {
 public:
    /**
   * @brief Construct a new Drone Wallet Decorator object, initializes funds to $0
   *
   * @param entity the drone entity to decorate onto
   */
  DroneWalletDecorator(IEntity* entity) : IWalletDecorator(entity) {
    balance = 0;
  }
  /**
   * @brief Wallet Destructor
   */
  ~DroneWalletDecorator();

  /**
   * @brief Gets the nearest entity in the scheduler
   * @param scheduler Vector containing all the entities in the system
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the entity's position in the physical system, with added functionality from Wallet Decorator.
   * @param dt The time step of the update.
   * @param scheduler The list of all entities in the system.
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Calculate the cost of a drone trip using beeline distace plus a flat fee
   * @param start A Vector 3 containing the starting coordinates of the trip
   * @param end A Vector3 containing the ending coordinates of the trip
  */
  float TripCost(Vector3 start, Vector3 end);
};

#endif
