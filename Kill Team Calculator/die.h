#pragma once
#include <cstdint>
#include <stdexcept>

struct die_counter
{
    uint16_t ones = 0;
    uint16_t twos = 0;
    uint16_t threes = 0;
    uint16_t fours = 0;
    uint16_t fives = 0;
    uint16_t sixes = 0;

    void add(uint16_t roll)
    {
        switch (roll)
        {
        case 1: ++ones; break;
        case 2: ++twos; break;
        case 3: ++threes; break;
        case 4: ++fours; break;
        case 5: ++fives; break;
        case 6: ++sixes; break;
        }
    }

    uint16_t& operator[](uint16_t index)
    {
        switch (index)
        {
        case 1: return ones;
        case 2: return twos;
        case 3: return threes;
        case 4: return fours;
        case 5: return fives;
        case 6: return sixes;
        default: throw std::out_of_range("Die rolls are between 1 and 6");
        }
	}

    uint16_t operator[](uint16_t index) const
    {
        switch (index)
        {
        case 1: return ones;
        case 2: return twos;
        case 3: return threes;
        case 4: return fours;
        case 5: return fives;
        case 6: return sixes;
        default: throw std::out_of_range("Die rolls are between 1 and 6");
        }
    }

    struct max_roll
    {
        uint16_t roll_value;
        uint16_t rolls;
	};

    max_roll max_under_number(uint16_t number) const
    {
        uint16_t max = 0;
		uint16_t max_num = 0;
        for (auto roll_value = 1; roll_value < number; ++roll_value)
        {
			auto rolls = (*this)[roll_value];
            if (rolls > max)
            {
				max = rolls;
                max_num = roll_value;
            }
		}
        if (max_num == 0)
        {
            max_num = 1;
        }
        max_roll result{max_num, max};
        return result;
	}
};