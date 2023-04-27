#include "RobotWalletDecorator.h" 

RobotWalletDecorator::RobotWalletDecorator(IEntity* entity) {
    this->entity = entity;
    balance = 20;
    hasPaid = false;
    //entity is created and wrapped in wallet decorator in SimulationModel.cc
}

RobotWalletDecorator::~RobotWalletDecorator() {
    delete entity;
}

void RobotWalletDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    //Added functionality here
    //if proximity < value and has not paid
        //withdraw TripCost
        //if !withdraw  && hasnt already called drone
            //call money delivery drone
    IEntity::Update(dt, scheduler);
}
