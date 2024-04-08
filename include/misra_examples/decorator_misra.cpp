// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// https://radioprog.ru/post/1483

#include <iostream>
#include <vector>
#include <memory>

extern "C" class Component {
 public:
  virtual ~Component() {}
  virtual std::string Operation() const = 0;
};

extern "C" class ConcreteComponent : public Component {
 public:
  std::string Operation() const override {
    return "ConcreteComponent";
  }
};

extern "C" class Decorator : public Component {
 protected:
  std::unique_ptr<Component> component_;

 public:
  explicit Decorator(std::unique_ptr<Component>& component) : component_{std::move(component)} {
  }

  std::string Operation() const override {
    return this->component_->Operation();
  }
};


extern "C" class ConcreteDecoratorA : public Decorator {

 public:
  ConcreteDecoratorA(std::unique_ptr<Component>& component) : Decorator(component) {
  }
  std::string Operation() const override {
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
  }
};

extern "C" class ConcreteDecoratorB : public Decorator {
 public:
  ConcreteDecoratorB(std::unique_ptr<Component>& component) : Decorator(component) {
  }

  std::string Operation() const override {
    return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
  }
};

extern "C" void ClientCode(std::unique_ptr<Component>& component) {
  std::cout << "RESULT: " << component->Operation();
}

int main() {

  auto simple = std::unique_ptr<Component>{std::make_unique<ConcreteComponent>()};
  std::cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  std::cout << "\n\n";

  auto decorator1 = std::unique_ptr<Component>{std::make_unique<ConcreteDecoratorA>(simple)};
  auto decorator2 =  std::unique_ptr<Component>{std::make_unique<ConcreteDecoratorB>(decorator1)};
  std::cout << "Client: Now I've got a decorated component:\n";
  ClientCode(decorator2);
  std::cout << "\n";

  return 0;
}