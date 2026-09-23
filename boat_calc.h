#pragma once
#include "boat_calc_base.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>

class Boat_Calc : public Boat_Calc_Base
{
protected:
    double time_hours = 0.0;

    void set_time(double val)
    {
        if (std::isnan(val))
        {
            throw std::invalid_argument("set_time: NaN is not allowed.");
        }
        if (std::isinf(val))
        {
            throw std::invalid_argument("set_time: infinity is not allowed.");
        }
        if (val < 0.0)
        {
            throw std::out_of_range("set_time: time below zero.");
        }

        time_hours = val;
    }

public:

    Boat_Calc() = default;

    Boat_Calc(double first_bs, double second_bs) : Boat_Calc_Base(first_bs, second_bs) {}

    Boat_Calc(double first_bs, double second_bs, double time_hr) : Boat_Calc_Base(first_bs, second_bs)
    {
        set_time(time_hr);
    }

    ~Boat_Calc() override = default;

    void set_time_hours(double time) { set_time(time); }

    double get_time_hours() const { return time_hours; }

    double get_moveaway_distance() const
    {
        return get_moveaway_speed() * time_hours;
    }

    double calc_moveaway_distance(double time_hr)
    {
        set_time(time_hr);
        return get_moveaway_distance();
    }
};
