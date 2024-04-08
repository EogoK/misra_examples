// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//https://www.geeksforgeeks.org/abstract-factory-pattern-c-design-patterns/

#include <iostream>
#include <memory>

extern "C" class Pizza {
public:
	virtual void bake() = 0;
	virtual void cut() = 0;
	virtual void box() = 0;
};

extern "C" class NewYorkCheesePizza : public Pizza {
public:
	void bake() override
	{
		std::cout << "Baking New York-style cheese pizza."
				<< std::endl;
	}

	void cut() override
	{
		std::cout << "Cutting New York-style cheese pizza."
				<< std::endl;
	}

	void box() override
	{
		std::cout << "Boxing New York-style cheese pizza."
				<< std::endl;
	}
};

// Concrete New York Pepperoni Pizza
extern "C" class NewYorkPepperoniPizza : public Pizza {
public:
	void bake() override
	{
		std::cout
			<< "Baking New York-style pepperoni pizza."
			<< std::endl;
	}

	void cut() override
	{
		std::cout
			<< "Cutting New York-style pepperoni pizza."
			<< std::endl;
	}

	void box() override
	{
		std::cout
			<< "Boxing New York-style pepperoni pizza."
			<< std::endl;
	}
};

// Concrete Chicago Cheese Pizza
extern "C" class ChicagoCheesePizza : public Pizza {
public:
	void bake() override
	{
		std::cout << "Baking Chicago-style cheese pizza."
				<< std::endl;
	}

	void cut() override
	{
		std::cout << "Cutting Chicago-style cheese pizza."
				<< std::endl;
	}

	void box() override
	{
		std::cout << "Boxing Chicago-style cheese pizza."
				<< std::endl;
	}
};

// Concrete Chicago Pepperoni Pizza
extern "C" class ChicagoPepperoniPizza : public Pizza {
public:
	void bake() override
	{
		std::cout << "Baking Chicago-style pepperoni pizza."
				<< std::endl;
	}

	void cut() override
	{
		std::cout
			<< "Cutting Chicago-style pepperoni pizza."
			<< std::endl;
	}

	void box() override
	{
		std::cout << "Boxing Chicago-style pepperoni pizza."
				<< std::endl;
	}
};

// Abstract Factory Interface
extern "C" class PizzaFactory {
public:
	virtual std::unique_ptr<Pizza> createCheesePizza() = 0;
	virtual std::unique_ptr<Pizza> createPepperoniPizza() = 0;
};

// Concrete New York Pizza Factory
extern "C" class NewYorkPizzaFactory : public PizzaFactory {
public:
	std::unique_ptr<Pizza> createCheesePizza() override
	{
		return std::move(std::make_unique<NewYorkCheesePizza>());
	}

	std::unique_ptr<Pizza> createPepperoniPizza() override
	{
		return std::move(std::make_unique<NewYorkPepperoniPizza>());
	}
};

// Concrete Chicago Pizza Factory
extern "C" class ChicagoPizzaFactory : public PizzaFactory {
public:
	std::unique_ptr<Pizza> createCheesePizza() override
	{
		return std::move(std::unique_ptr<Pizza>{std::make_unique<ChicagoCheesePizza>()});
	}

	std::unique_ptr<Pizza> createPepperoniPizza() override
	{
		return std::move(std::unique_ptr<Pizza>{std::make_unique<ChicagoPepperoniPizza>()});
	}
};

int main()
{
	// Create a New York Pizza Factory
	auto newYorkFactory = std::unique_ptr<PizzaFactory>{std::make_unique<NewYorkPizzaFactory>()};
	auto newYorkCheesePizza = newYorkFactory->createCheesePizza();
	auto newYorkPepperoniPizza = newYorkFactory->createPepperoniPizza();

	// Create a Chicago Pizza Factory
	auto chicagoFactory = std::unique_ptr<PizzaFactory>{std::make_unique<NewYorkPizzaFactory>()};
	auto chicagoCheesePizza = chicagoFactory->createCheesePizza();
	auto chicagoPepperoniPizza = chicagoFactory->createPepperoniPizza();

	// Order and prepare the pizzas
	newYorkCheesePizza->bake();
	newYorkCheesePizza->cut();
	newYorkCheesePizza->box();

	newYorkPepperoniPizza->bake();
	newYorkPepperoniPizza->cut();
	newYorkPepperoniPizza->box();

	chicagoCheesePizza->bake();
	chicagoCheesePizza->cut();
	chicagoCheesePizza->box();

	chicagoPepperoniPizza->bake();
	chicagoPepperoniPizza->cut();
	chicagoPepperoniPizza->box();


	return 0;
}
