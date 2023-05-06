#include "ATMDrone.h"
#include "RobotWalletDecorator.h"
#include <iostream>

ATMDrone::ATMDrone(JsonObject& obj): Drone(obj) {}

void ATMDrone::GetNearestEntity(std::vector<IEntity*> scheduler) {  //is override needed here?
  nearestEntity = nullptr;
  robo = nullptr;
  pickedUp = false;
  atFinal = false;
  available = true;

  float minDisRob = std::numeric_limits<float>::max();
  float minDisPS = std::numeric_limits<float>::max();
  for (auto ent : scheduler) {
    std::string type = ent->GetDetails()["type"];
    float disToEntity = this->position.Distance(ent->GetPosition());
    RobotWalletDecorator* rob = dynamic_cast<RobotWalletDecorator*>(ent); //Dynamic type cast 
    if (type.compare("robot") == 0 && rob->GetNeedsMoney() && disToEntity <= minDisRob) {
      robo = ent;
      minDisRob = disToEntity;
    }
    if (type.compare("paymentStation") == 0 && disToEntity <= minDisPS) {
      minDisPS = disToEntity;
      nearestEntity = ent;
    }
  }

  if (nearestEntity && robo) {
      // set availability to the nearest entity
    nearestEntity->SetAvailability(false);
    available = false;

    destination = nearestEntity->GetPosition();
    Vector3 finalDestination = robo->GetPosition();
    toRobot = new BeelineStrategy(position, destination);
    toFinalDestination = new BeelineStrategy(destination, finalDestination);
  }
}