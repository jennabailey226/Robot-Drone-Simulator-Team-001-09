#include "ATMDroneDecorator.h"

void ATMDroneDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    if (entity->AtInitialDestination()) {
        ///*PaymentStation*/.Withdraw(50, "bank", this);
    }
    if (entity->AtFinalDestination()) {
        //withdraw(50);
       // /*RobotWallet*/.deposit(50);
    }
    else {
        entity->Update(dt, scheduler);
    }
}

