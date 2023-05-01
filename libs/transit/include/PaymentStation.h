#ifndef PAYMENTSTATION_H_
#define PAYMENTSTATION_H_

#include "IEntity.h"

/**
 * @class PaymentStation
 * @brief Represents a payment station in a physical system.
 */
class PaymentStation : public IEntity {
 public:
  /**
   * @brief Payment stations are created with a position
   * @param obj JSON object containing the payment station's information
   */
  PaymentStation(JsonObject& obj);

  /**
   * @brief Destructor.
   */
  ~PaymentStation();

  /**
   * @brief Gets the position of the payment station.
   * @return The position of the payment station.
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction the payment station is facing.
   * @return The direction of the payment station.
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destination of the payment station (it's current position).
   * @return The destination of the payment station.
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the details of the payment station.
   * @return The details of the payment station.
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the speed of the payment station (0).
   * @return The speed of the payment station.
   */
  float GetSpeed() const { return 0; }

  /**
   * @brief Gets the availability of the payment station for use.
   * @return The availability of the payment station.
   */
  bool GetAvailability() const { return availability; }

  /**
   * @brief Get the Strategy Name (none)
   * @return Streategy name (none)
   */
  std::string GetStrategyName() const { return ""; }

  /**
   * @brief Sets the availability of the payment station.
   * @param choice The desired availability of the payment station.
   */
  void SetAvailability(bool choice) { availability = choice; }

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  bool available;
};

#endif