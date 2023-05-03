#include "DroneWalletDecorator.h"
#include "Drone.h"

DroneWalletDecorator::~DroneWalletDecorator() {}

void DroneWalletDecorator::GetNearestEntity(std::vector<IEntity*> scheduler) {
    Drone * ent = dynamic_cast<Drone*>(entity);
    ent->GetNearestEntity(scheduler);
    // if (this->balance < 100) {
    //     //select an ATM as the nearest entity to go drop off money
    //     float minDis = std::numeric_limits<float>::max();
    //     for (auto entity : scheduler) {
    //         std::string type = entity->GetDetails()["type"];
    //         if (entity->GetAvailability() && type.compare("paymentStation") == 0) {
    //             float disToEntity = entity->GetPosition().Distance(entity->GetPosition());
    //             if (disToEntity <= minDis ) {
    //                 minDis = disToEntity;
    //                 entity->ReturnNearestEntity() = entity;
    //             }
    //         }
    //     }
    // }
    // Otherwise find non-atm entity to route towards
    // Drone::GetNearestEntity(scheduler);

}

void DroneWalletDecorator::Update(double dt, std::vector<IEntity*>scheduler) {
    //Added Functionality here
    //if at atm
        //deposit money
    //if at robot
        //charge robot
            //if successful pick up and proceed with trip
            //if not successful change robot needsMoney to true
            //delete nearestEntity so it can re-selecet
    entity->Update(dt, scheduler);
}

float DroneWalletDecorator::TripCost(Vector3 start, Vector3 end) {
    double distance = sqrt(pow((end.x-start.x),2) + pow((end.y-end.x), 2));
    float cost = 3 + (distance/70.0);
    return cost;
}
