#include "ATMDroneDecorator.h"

void ATMDroneDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    ATMDrone* ent = dynamic_cast<ATMDrone*>(entity);
    if (entity->AtInitialDestination()) {
        PaymentStation* atm = dynamic_cast<PaymentStation*>(ent->ReturnNearestEntity());
        atm->Withdraw(50, "bank", this);
    }
    if (entity->AtFinalDestination()) {
        RobotWalletDecorator* robo = dynamic_cast<RobotWalletDecorator*>(ent->GetRobo());
        withdraw(50);
        robo->deposit(50);
    }
    else {
        entity->Update(dt, scheduler);
    }
}

