#ifndef WALLET_DECORATOR_H_
#define WALLET_DECORATOR_H_

#include "IEntity.h"

class IWalletDecorator : public IEntity {
 protected:
    float balance;
    IEntity* entity;
 public:
//     /**
//    * @brief Construct a new Wallet Decorator object
//    *
//    * @param strategy the entity to decorate onto
//    */
//   IWalletDecorator(IEntity* entity);

  /**
   * @brief Wallet Destructor
   */
  ~IWalletDecorator() { delete entity; }

  /**
   * @brief Updates the entity's position in the physical system, with added functionality from Wallet Decorator.
   * @param dt The time step of the update.
   * @param scheduler The list of all entities in the system.
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) override {}

  /**
   * @brief Gets the position of the entity.
   * @return The position of the entity.
   */
  virtual Vector3 GetPosition() const override {
   return this->entity->GetPosition();
  }

  /**
   * @brief Gets the direction of the entity.
   * @return The direction of the entity.
   */
  virtual Vector3 GetDirection() const override {
   return this->entity->GetDirection();
  }

  /**
   * @brief Gets the destination of the entity.
   * @return The destination of the entity.
   */
  virtual Vector3 GetDestination() const override {
   return this->entity->GetDestination();
  }

  /**
   * @brief Gets the details of the entity.
   * @return The details of the entity.
   */
  virtual JsonObject GetDetails() const override {
   return this->entity->GetDetails();
  }

  /**
   * @brief Gets the speed of the entity.
   * @return The speed of the entity.
   */
  virtual float GetSpeed() const {
   return this->entity->GetSpeed();
  } 

  /**
   * @brief Adds money to entity's wallet.
   * @param The money in dollars to be added.
   */
  void balanceAdd(float payment) {
   balance+=payment;
  }

  /**
   * @brief Removes money from the entity's wallet.
   * @param The money in dollars to be withdrawn.
   * @return If withdraw was successful (payment removed and balance non-negative).
   */
  bool withdraw(float payment) {
   if (balance-payment < 0) {
      return false;
   } else {
      balance-=payment;
      return true;
   }
  }

};


#endif
