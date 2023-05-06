#ifndef WALLET_DECORATOR_H_
#define WALLET_DECORATOR_H_

#include "IEntity.h"

class IWalletDecorator : public IEntity {
 protected:
  float balance;
  IEntity* entity;

 public:
  /**
  * @brief Construct a new Wallet Decorator object
  *
  * @param strategy the entity to decorate onto
  */
  IWalletDecorator(IEntity* entity) {
      this->entity = entity;
      balance = 0;   
   }

   /**
   * @brief Wallet Destructor
   */
   ~IWalletDecorator() { delete entity; }

   /**
   * @brief Updates the entity's position in the physical system, with added functionality from Wallet Decorator.
   * @param dt The time step of the update.
   * @param scheduler The list of all entities in the system.
   */
   virtual void Update(double dt, std::vector<IEntity*> scheduler) /*override*/ {}

   /**
   * @brief Gets the position of the entity.
   * @return The position of the entity.
      */
   virtual Vector3 GetPosition() const /*override*/ {
      return this->entity->GetPosition();
   }

   /**
   * @brief Gets the direction of the entity.
   * @return The direction of the entity.
   */
   virtual Vector3 GetDirection() const /*override*/ {
   return this->entity->GetDirection();
   }

   /**
   * @brief Gets the destination of the entity.
   * @return The destination of the entity.
   */
   virtual Vector3 GetDestination() const /*override*/ {
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
   * @param payment The money in dollars to be added.
   */
   void deposit(float payment) {
      balance+=payment;
   }

   /**
   * @brief Removes money from the entity's wallet.
   * @param payment The money in dollars to be withdrawn.
   * @return If withdraw was successful (payment removed and balance non-negative).
   */
   bool withdraw(float payment) {
      if (balance-payment < 0) {
         return false;
         std::cout << "withdraw failed; not enough funds" << std::endl;
      } else {
         balance-=payment;
         return true;
      }
   }

   /**
   * @brief Gets the color of the drone
   * @return The color of the drone
   */
   virtual std::string GetColor() const { return entity->GetColor(); }

   /**
   * @brief Gets the availability of the entity.
   * @return The availability of the entity.
   */
   virtual bool GetAvailability() const { return entity->GetAvailability(); }

   /**
   * @brief Get the Strategy Name
   *
   * @return Streategy name
   */
   virtual std::string GetStrategyName() const { return entity->GetStrategyName(); }

   /**
   * @brief Set the Strategy Name
   *
   * @param strategyName_ Strategy name
   */
   virtual void SetStrategyName(std::string strategyName_) { 
      entity->SetStrategyName(strategyName_); 
   }

   /**
   * @brief Sets the availability of the entity.
   * @param choice The desired availability of the entity.
   */
   virtual void SetAvailability(bool choice) { 
      entity->SetAvailability(choice); 
   }

   /**
   * @brief Sets the graph object used by the entity in the simulation.
   * @param graph The IGraph object to be used.
   */
   void SetGraph(const IGraph* graph) override{ entity->SetGraph(graph); }

   /**
   * @brief Sets the position of the entity.
   * @param pos_ The desired position of the entity.
   */
   virtual void SetPosition(Vector3 pos_) { entity->SetPosition(pos_); }

   /**
   *@brief Set the direction of the entity.
   *@param dir_ The new direction of the entity.
   */
   virtual void SetDirection(Vector3 dir_) { entity->SetDirection(dir_); }

   /**
   *@brief Set the destination of the entity.
   *@param des_ The new destination of the entity.
   */
   virtual void SetDestination(Vector3 des_) { entity->SetDestination(des_); }

   /**
   * @brief Sets the color of the drone
   * @param col_ The new color of the drone
   */
   virtual void SetColor(std::string col_) { entity->SetColor(col_); }

   /**
   * @brief Rotate the entity.
   * @param angle The angle to rotate the entity by.
   */
   virtual void Rotate(double angle) { entity->Rotate(angle); }

   /**
   * @brief Make the entity jump.
   * @param height The height to make the entity jump.
   */
   virtual void Jump(double height) { entity->Jump(height); }


   /**
   * @brief Return a random float between two floating point values
   * @param Min The lowest possible float that can be selected
   * @param Max The maximum possible float that can be selected
   */
   virtual float Random(float Min, float Max) { return entity->Random(Min, Max); }

   /**
   * @brief Get the entity currently set as nearest entity.
   * @return the entity currently set as nearest self.
   */
   IEntity* ReturnNearestEntity() { return entity->ReturnNearestEntity(); }

   /**
   * @brief Allow access to modifying nearest entity by wallet decorators
   * @param nearEntity The entity to be set as nearest to self.
   */
   void SetNearestEntity(IEntity* nearEntity) { 
      entity->SetNearestEntity(nearEntity); 
   }
};

#endif
