#include "PaymentStationFactory.h"
#include <iostream>

IEntity* PaymentStationFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("paymentStation") == 0) {
    std::cout << "Payment Station Created" << std::endl;
    return new PaymentStation(entity);
  }
  return nullptr;
}