#pragma once

#include "flags.hpp"
#include <type_traits>

namespace cmx
{


template<typename T, typename = int>
struct _basehasname : public std::false_type { };

template<typename T>
struct _basehasname <T, decltype((void) T::name, 0)> : public std::true_type { };


template<typename T, typename = std::false_type>
struct _BaseTypeName : std::false_type { };

template<typename T>
struct _BaseTypeName<T, std::true_type> : std::true_type { };

template<typename T>
struct TypeName : public _BaseTypeName<TypeName<T>, _basehasname<TypeName<T>>>
{
    using valid_t = _basehasname<TypeName<T>>;
    using basetype_t = _BaseTypeName<TypeName<T>>;
    using this_t = TypeName<T>;

    typedef valid_t k_t;

    static_assert(valid_t::value, "No name available for this type");
};

template<typename T, typename = int>
struct hasname : public std::false_type { };

template<typename T>
struct hasname <T, decltype((void) TypeName<T>::name, 0)> : public std::true_type { };

} // namespace cmx

#define CMX_MAP_NAME(type, strName)   \
namespace cmx                   \
{                               \
    template<>                  \
    struct TypeName<type> : _BaseTypeName<TypeName<type>>   \
    {                                       \
        static constexpr char name[] = strName;    \
    };                                            \
}

/**
 * @brief 
 * @deprecated
 */
#define CMX_ENABLE_NAME(type) CMX_MAP_NAME(type, #type)
