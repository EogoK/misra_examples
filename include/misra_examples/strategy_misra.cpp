// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// https://radioprog.ru/post/1505

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <memory>

extern "C" class Strategy
{
public:
    virtual ~Strategy() {}
    virtual std::string DoAlgorithm(const std::vector<std::string>& data) const = 0;
};


extern "C" class Context
{

private:
    std::unique_ptr<Strategy> strategy_;

public:
    Context(std::unique_ptr<Strategy> strategy) : strategy_(std::move(strategy))
    {
    }
    ~Context()
    {
        this->strategy_.reset();
    }
    void set_strategy(std::unique_ptr<Strategy> strategy)
    {
        this->strategy_.reset();
        this->strategy_ = std::move(strategy);
    }

    void DoSomeBusinessLogic() const
    {

        std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
        std::string result = this->strategy_->DoAlgorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
        std::cout << result << "\n";
    }
};


extern "C" class ConcreteStrategyA : public Strategy
{
public:
    std::string DoAlgorithm(const std::vector<std::string>& data) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));

        return result;
    }
};
extern "C" class ConcreteStrategyB : public Strategy
{
    std::string DoAlgorithm(const std::vector<std::string>& data) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));
        for (int i = 0; i < result.size() / 2; i++)
        {
            (void)std::swap(result[i], result[result.size() - i - 1]);
        }

        return result;
    }
};


extern "C" void ClientCode()
{
    auto context = std::make_unique<Context>(std::move(std::unique_ptr<Strategy>{std::make_unique<ConcreteStrategyA>()}));
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context->DoSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    auto strategy_b = std::unique_ptr<Strategy>{std::make_unique<ConcreteStrategyB>()};

    context->set_strategy(std::move(strategy_b));
    context->DoSomeBusinessLogic();
}

int main()
{
    ClientCode();
    return 0;
}