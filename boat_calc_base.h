#pragma once
#include <cmath>
#include <algorithm>
#include <stdexcept>

class Boat_Calc_Base
{
public:
    enum Boat_Num
    {
        FIRST = 1,
        SECOND
    };

protected:
    double boat_speed_first  = 0.0;
    double boat_speed_second = 0.0;

public:

    Boat_Calc_Base() = default;

    Boat_Calc_Base(double first_bs, double second_bs)
    {
        set_boat_speed(FIRST, first_bs);
        set_boat_speed(SECOND, second_bs);
    }

    virtual ~Boat_Calc_Base() = default;

    void set_boat_speed(Boat_Num num, double val)
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

        switch (num)
        {
            case FIRST:  boat_speed = &boat_speed_first;  break;
            case SECOND: boat_speed = &boat_speed_second; break;
            default: throw std::invalid_argument("set_boat_speed: invalid boat number.");
        }

        *boat_speed = val;
    }

    double get_boat_speed(Boat_Num num) const
    {
        switch (num)
        {
            case FIRST:  return boat_speed_first;
            case SECOND: return boat_speed_second;
            default: throw std::invalid_argument("get_boat_speed: invalid boat number.");
        }
    }

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
        set_boat_speed(FIRST, first_bs);
        set_boat_speed(SECOND, second_bs);
        return get_moveaway_speed();
    }
};
