#ifndef PAYMENT_STATION_FACTORY_H_
#define PAYMENT_STATION_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "PaymentStation.h"

/**
 *@brief Drone Factory to produce Drones class.
 **/
class PaymentStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for IEntityFactory class.
   **/
  ~PaymentStationFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif