#ifndef ATM_DRONE_FACTORY_H_
#define ATM_DRONE_FACTORY_H_

#include <vector>

#include "DroneFactory.h"
#include "ATMDrone.h"
#include "ATMDroneDecorator.h"

/**
 *@brief Drone Factory to produce Drones class.
 **/
class ATMDroneFactory : public DroneFactory {
 public:
  /**
   * @brief Destructor for IEntityFactory class.
   **/
  virtual ~ATMDroneFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity) {
    std::string type = entity["type"];
    if (type.compare("ATMDrone") == 0) {
        std::cout << "ATM Drone Created" << std::endl;
        return new ATMDroneDecorator(new ATMDrone(entity));
    }
    return nullptr;
  }
};

#endif