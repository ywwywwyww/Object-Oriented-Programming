#ifndef PIZZA_H_
#define PIZZA_H_

#include <string>
class Pizza {
  // The abstract class for all types of pizza.
 protected:
  std::string id_;

 public:
  Pizza(std::string id) : id_(id) {}
  std::string get_id() const { return id_; }
  virtual ~Pizza() = default;
};

#endif /* PIZZA_H_ */