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
    //entity is created in Drone.cc and wrapped in wallet decorator in DroneFactory.cc
  };
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

  float TripCost(Vector3 start, Vector3 end);

  IEntity* ReturnNearestEntity() { return entity->ReturnNearestEntity(); }

  void SetNearestEntity(IEntity* nearEntity) { entity->SetNearestEntity(nearEntity); }

};

#endif
