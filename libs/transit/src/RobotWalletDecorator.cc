#include "RobotWalletDecorator.h" 

RobotWalletDecorator::RobotWalletDecorator(IEntity* entity) {
    this->entity = entity;
    balance = 20;
    //Unsure of how entity is created/when robot constructor is called
}

RobotWalletDecorator::~RobotWalletDecorator() {
    delete entity;
}

void RobotWalletDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    IEntity::Update(dt, scheduler);
    //Added functionality here
}
