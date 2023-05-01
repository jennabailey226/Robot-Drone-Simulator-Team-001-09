#include "RobotFactory.h"
#include "RobotWalletDecorator.h"
#include <iostream>

IEntity* RobotFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("robot") == 0) {
    std::cout << "Robot Created" << std::endl;
    return new RobotWalletDecorator(new Robot(entity));
  }
  return nullptr;
}
