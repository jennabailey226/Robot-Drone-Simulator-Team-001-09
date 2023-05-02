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
    RobotWalletDecorator* ent = dynamic_cast<RobotWalletDecorator*>(entity); //Dynamic type cast 
    if ((entity->GetAvailability()) && (ent->getNeedsMoney()==true)) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestEntity = entity;
      }
    }
  }

  if (nearestEntity) {
      // set availability to the nearest entity
    nearestEntity->SetAvailability(false);
    available = false;
    pickedUp = false;

    destination = nearestEntity->GetPosition();
    Vector3 finalDestination = nearestEntity->GetDestination();

    toRobot = new BeelineStrategy(position, destination);

    std::string strat = nearestEntity->GetStrategyName();
    if (strat == "astar")
      toFinalDestination =
        new JumpDecorator(new AstarStrategy(destination, finalDestination, graph));
    else if (strat == "dfs")
      toFinalDestination =
        new SpinDecorator(new JumpDecorator(new DfsStrategy(destination, finalDestination, graph)));
    else if (strat == "dijkstra")
      toFinalDestination =
        new JumpDecorator(new SpinDecorator(new DijkstraStrategy(destination, finalDestination, graph)));
    else
      toFinalDestination = new BeelineStrategy(destination, finalDestination);
  }
}

void ATMDrone::Update(double dt, std::vector<IEntity*> scheduler) {
  
}
