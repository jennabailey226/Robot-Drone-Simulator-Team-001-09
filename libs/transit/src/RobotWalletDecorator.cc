#include "RobotWalletDecorator.h" 
#include <iostream>

RobotWalletDecorator::~RobotWalletDecorator() {}

void RobotWalletDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    //Added functionality here
    //if proximity < value and has not paid
        //withdraw TripCost
        //if !withdraw  && hasnt already called drone
            //call money delivery drone
    IEntity::Update(dt, scheduler);
}
