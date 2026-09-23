#pragma once
#include <cmath>
#include <algorithm>
#include <stdexcept>

class Boat_Calc_Base
{
protected:
    double boat_speed_first  = 0.0;
    double boat_speed_second = 0.0;

    void set_boat_speed(int idx, double val)
    {
        if (std::isnan(val))
        {
            throw std::invalid_argument("set_boat_speed: NaN is not allowed.");
        }
        if (std::isinf(val))
        {
            throw std::invalid_argument("set_boat_speed: infinity is not allowed.");
        }

        double* boat_speed;

        if      (idx == 1) boat_speed = &boat_speed_first;
        else if (idx == 2) boat_speed = &boat_speed_second;
        else throw std::invalid_argument("set_second_boat_speed: invalid boat index.");

        *boat_speed = val;
    }

public:

    Boat_Calc_Base() = default;

    Boat_Calc_Base(double first_bs, double second_bs)
    {
        set_boat_speed(1, first_bs);
        set_boat_speed(2, second_bs);
    }

    virtual ~Boat_Calc_Base() = default;

    void set_first_boat_speed(double speed)  { set_boat_speed(1, speed); }
    void set_second_boat_speed(double speed) { set_boat_speed(2, speed); }

    double get_first_boat_speed()  const { return boat_speed_first; }
    double get_second_boat_speed() const { return boat_speed_second; }

    double get_moveaway_speed() const
    {
        bool is_first_speed_positive = boat_speed_first > 0.0;
        bool is_second_speed_positive = boat_speed_second > 0.0;

        if (is_first_speed_positive == is_second_speed_positive)
        {
            return std::max(boat_speed_first, boat_speed_second) - std::min(boat_speed_first, boat_speed_second);
        }
        else
        {
            return std::abs(boat_speed_first) + std::abs(boat_speed_second);
        }
    }

    double calc_moveaway_speed(double first_bs, double second_bs)
    {
        set_boat_speed(1, first_bs);
        set_boat_speed(2, second_bs);
        return get_moveaway_speed();
    }
};
