#include "AND_Gate.hpp"

AND_Gate::AND_Gate(const Wire *signal_1, const Wire *signal_2, Wire *signal_3)
    : input_1(signal_1), input_2(signal_2), output(signal_3)
{
}

bool AND_Gate::update()
{
    auto a = input_1->get();
    auto b = input_2->get();

    if (a == Signal::on && b == Signal::on)
    {
        return output->set(Signal::on);
    }
    else if (a == Signal::off || b == Signal::off)
    {
        return output->set(Signal::off);
    }
    else
    {
        return output->set(Signal::ud);
    }
}