#ifndef ATMDRONE_H_
#define ATMDRONE_H_

#include "Drone.h"

class ATMDrone : public Drone {
 public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  ATMDrone(JsonObject& obj);

  /**
   * @brief Updates the ATM drone's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  
  /**
   * @brief Gets the nearest robot that needs money in the scheduler
   * @param scheduler Vector containing all the entities in the system
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);
};

#endif
