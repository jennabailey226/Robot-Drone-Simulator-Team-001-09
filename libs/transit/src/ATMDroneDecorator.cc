#include "ATMDroneDecorator.h"

void ATMDroneDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    ATMDrone* ent = dynamic_cast<ATMDrone*>(entity);
    if (entity->GetAvailability()) {
        ent->GetNearestEntity(scheduler);
    }

    if (entity->AtInitialDestination()) {
        PaymentStation* atm = dynamic_cast<PaymentStation*>(ent->ReturnNearestEntity());
        atm->Withdraw(100, "National Bank", this);
        entity->Update(dt, scheduler);
    }
    else {
        entity->Update(dt, scheduler);
        if (entity->AtFinalDestination()) {
            RobotWalletDecorator* robo = dynamic_cast<RobotWalletDecorator*>(ent->GetRobo());
            float amount = balance;
            withdraw(amount);
            robo->deposit(amount);
            std::cout << "ATM Drone gave Robot $" << amount << std::endl;
            robo->SetNeedsMoney(false);
        }
    }
}

