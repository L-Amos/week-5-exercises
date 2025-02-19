#include <iostream>
#include "DiscreteFunction.h"
#include <vector>

int main()
{
    std::vector<double> ys(21);
    double delta_x = 1.0 / 20;
    for(size_t i = 0; i < ys.size(); i++)
    {
        double x = delta_x * i;
        ys[i] = x*x;
    }   
    DiscreteFunction DF(ys, 0, 1);
    DF.setIntegrator(std::make_unique<TrapeziumIntegrator>());
    std::cout << "Trapezium Result: " << DF.integrate() << std::endl;
    DF.setIntegrator(std::make_unique<SimpsonIntegrator>());
    std::cout << "Simpson Result: " << DF.integrate() << std::endl;

    return 0;
}