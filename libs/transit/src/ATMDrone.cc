#include "ATMDrone.h"
#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"
#include "RobotWalletDecorator.h"
#include <iostream>

ATMDrone::ATMDrone(JsonObject& obj): Drone(obj) {}

void ATMDrone::GetNearestEntity(std::vector<IEntity*> scheduler) {  //is override needed here?
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : scheduler) {
    std::string type = entity->GetDetails()["type"];
    RobotWalletDecorator* ent = dynamic_cast<RobotWalletDecorator*>(entity); //Dynamic type cast 
    if (entity->GetAvailability()) {
      if (ent->getNeedsMoney()) {
        robo = entity;
      }
      if (type.compare("paymentStation") == 0) {
        float disToEntity = this->position.Distance(entity->GetPosition());
        if (disToEntity <= minDis) {
          minDis = disToEntity;
          nearestEntity = entity;
        }
      }
    }
  }

  if (nearestEntity) {
      // set availability to the nearest entity
    nearestEntity->SetAvailability(false);
    available = false;
    pickedUp = false;
    atFinal = false;

    destination = nearestEntity->GetPosition();
    Vector3 finalDestination = robo->GetPosition();
    toRobot = new BeelineStrategy(position, destination);
  }
}