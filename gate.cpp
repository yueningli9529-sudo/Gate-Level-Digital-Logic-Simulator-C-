#include <iostream>
#include <memory>
#include <vector>
// ———————————————————————signal———————————————————————
enum class Signal
{
    off,
    on,
    ud
};
std::ostream &operator<<(std::ostream &out, const Signal &s);

// ———————————————————————GATE———————————————————————
class Gate
{
public:
    virtual bool update() = 0;
    virtual ~Gate() = default; // delete gate*会先调用子类的
};

// ——————AND——————
class AND_Gate : public Gate
{
public:
    AND_Gate(const Signal *signal_1, const Signal *signal_2, Signal *signal_3);
    bool update() override;

private:
    const Signal *input_1; // 只是通过这个指针不能改，可以通过其他指针改
    const Signal *input_2;
    Signal *output; // 输出端口有改写权
};

// ————————————————————————circuit———————————————————————
class Circuit
{
public:
    Circuit();
    void add_gate(std::unique_ptr<Gate> a);
    bool step();
    void run_through();

private:
    std::vector<std::unique_ptr<Gate>> gates;
};

// ————————————————————————main————————————————————————
int main()
{
    Signal signal_1 = Signal::ud;
    Signal signal_2 = Signal::off;
    Signal signal_3 = Signal::ud;
    Circuit circuit;
    // add gate
    circuit.add_gate(std::unique_ptr<Gate>(new AND_Gate(&signal_1, &signal_2, &signal_3)));
    circuit.run_through();
    std::cout << signal_3 << std::endl;
}

//
//
// ———————————————————————def———————————————————————
std::ostream &operator<<(std::ostream &out, const Signal &s)
{
    if (s == Signal::off)
    {
        out << "off";
    }
    else if (s == Signal::on)
    {
        out << "on";
    }
    else
    {
        out << "ud";
    }
    return out;
}
AND_Gate::AND_Gate(const Signal *signal_1, const Signal *signal_2, Signal *signal_3)
    : input_1(signal_1), input_2(signal_2), output(signal_3)
{
}

bool AND_Gate::update()
{
    Signal temp = *output;
    if (*input_1 == Signal::on && *input_2 == Signal::on)
    {
        *output = Signal::on;
    }
    else if (*input_1 == Signal::off || *input_2 == Signal::off)
    {
        *output = Signal::off;
    }
    else
    {
        *output = Signal::ud;
    }
    return *output != temp;
}

Circuit::Circuit()
{
    gates.reserve(10);
}

void Circuit::add_gate(std::unique_ptr<Gate> a)
{
    gates.push_back(std::move(a));
}

bool Circuit::step()
{
    bool changed = false;
    for (const std::unique_ptr<Gate> &i : gates) // 一定要引用啊
    {
        changed |= i->update();
    }
    return changed;
}

void Circuit::run_through()
{
    int count = 0;
    int max = 1000;
    while (step() && count < max)
    {
        count++;
    }
    if (count == max)
    {
        std::cerr << "Warning: circuit did not stabilize after "
                  << max << " iterations\n";
    }
}
