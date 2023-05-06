#include "DroneWalletDecorator.h"
#include "Drone.h"
#include "RobotWalletDecorator.h"
#include "PaymentStation.h"

DroneWalletDecorator::~DroneWalletDecorator() {}

void DroneWalletDecorator::GetNearestEntity(std::vector<IEntity*> scheduler) {
    if (this->balance > 100) {
        entity->SetNearestEntity(nullptr);
        std::cout << "Drone has big moneys. Gotta deposit some" << std::endl;
        entity->SetAvailability(false);
        //select an ATM as the nearest entity to go drop off money
        float minDis = std::numeric_limits<float>::max();
        for (auto ent : scheduler) {
            std::string type = ent->GetDetails()["type"];
            if (ent->GetAvailability() && type.compare("paymentStation") == 0) {
                float disToEntity = entity->GetPosition().Distance(ent->GetPosition());
                if (disToEntity <= minDis ) {
                    minDis = disToEntity;
                    entity->SetNearestEntity(ent);
                }
            }
        }
    }
    Drone* drone = dynamic_cast<Drone*>(entity);
    drone->GetNearestEntity(scheduler);
}

void DroneWalletDecorator::Update(double dt, std::vector<IEntity*>scheduler) {
    if (entity->GetAvailability()) {
        GetNearestEntity(scheduler);
    }
    //If at robot
    else {
        IEntity* nearest = this->ReturnNearestEntity();
        std::string type = nearest->GetDetails()["type"];
        if (entity->AtInitialDestination()) {   //does this need robot type checking
            //Case for at robot/object to be picked up 
            if (type.compare("paymentStation") != 0) {
                RobotWalletDecorator* robo = dynamic_cast<RobotWalletDecorator*>(nearest);
                float cost = TripCost(nearest->GetPosition(), nearest->GetDestination());
                //If withdrawing TripCost funds is successfull, pick up entity and continue
                if (!robo->GetNeedsMoney() && robo->withdraw(cost)) {
                    std::cout << "Trip cost is $" << cost << std::endl;
                    std::cout << "Robot paid Drone $" << cost << " for a trip" << std::endl << std::endl;
                    this->deposit(cost);
                    entity->Update(dt, scheduler);
                } else {        //robot cannot pay
                    if (!robo->GetNeedsMoney()) {
                        std::cout << "Trip cost is $" << cost << std::endl;
                        std::cout << "Robot doesn't have enough money. Big L" << std::endl;
                    }
                    robo->SetNeedsMoney(true);
                }
            //Case for at payment station/drop off money
            } else {
                PaymentStation* ps = dynamic_cast<PaymentStation*>(nearest);
                ps->Deposit(balance, "National Bank", this);
                entity->SetAvailability(true);
                entity->Update(dt, scheduler);
            }
        }
        else {
            entity->Update(dt, scheduler);
        }
    }
}

float DroneWalletDecorator::TripCost(Vector3 start, Vector3 end) {
    double distance = sqrt(pow((end.x-start.x),2) + pow((end.y-end.x), 2));
    float cost = 3 + (distance/70.0);
    return cost;
}
