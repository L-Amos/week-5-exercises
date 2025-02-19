#pragma once 
#include <memory>
#include <vector>
#include <functional>


class SimpsonIntegrator
{
    public:
    SimpsonIntegrator();

    double integrate(const double delta_x, const std::vector<double> &ys);
};

class TrapeziumIntegrator
{
    public:
    TrapeziumIntegrator();

    double integrate(const double delta_x, const std::vector<double> &ys);
};

class DiscreteFunction
{
    public:
    DiscreteFunction(std::vector<double> y, double x_min, double x_max, std::unique_ptr<TrapeziumIntegrator> integrator_ptr);
    void setTrapeziumIntegrator(std::unique_ptr<TrapeziumIntegrator> ptr);
    double integrate();

    private:
    std::unique_ptr<TrapeziumIntegrator> integrator;
    std::vector<double> ys;
    double min_x;
    double max_x;
    double delta_x;
};

