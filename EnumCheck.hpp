#pragma once

#include "common.hpp"
#include <type_traits>


namespace cmx
{

template <typename T, T... Items> struct EnumCheck;

template <typename T>
struct EnumCheck<T>
{
    template <typename Value_type>
    static constexpr bool contains(Value_type&& value)
    {
        return false;
    }
};

/**
 * @brief Checks if a value is castable and is an enumerator of an enum
 * 
 * @tparam T type of enum
 * @tparam first_item first enumerator of the enum
 * @tparam remaining_items all other enumerators of the enum
 *
 * @code {.cpp}
 * 
 * enum class Color
 * {
 *      RED = 0,
 *      BLUE = 1,
 *      GREEN = 2
 * };
 * 
 * using my_checker = EnumCheck<Color, Color::RED, Color::BLUE, Color::GREEN>;
 * 
 * bool is_1_valid = my_checker::contains(1);   // true - 1 is Color::BLUE
 * bool is_3_valid = my_checker::contains(3);   // false - max value is 3 (Color::GREEN)
 * 
 * @endcode
 */
template <typename T, T first_item, T... remaining_items>
struct EnumCheck<T, first_item, remaining_items...>
{
private:
    using remaining_set = EnumCheck<T, remaining_items...>;

public:

    /**
     * @brief Determines if the argument is a valid enumerator in the enum
     * 
     * @tparam Value_type type of the argument
     * @param value potential value of an enumerator
     * @return true value has an enumerator in the enum
     * @return false value is not an enumerator in the enum
     */
    template <typename Value_type>
    static constexpr bool contains(Value_type&& value)
    {
        return ( value == static_cast<typename std::remove_reference<Value_type>::type>(first_item) ) || remaining_set::contains(value);
    }
};

}; // namespace cmx
