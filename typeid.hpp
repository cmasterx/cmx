#ifndef TYPEID_H
#define TYPEID_H

#ifndef CMX_TYPEID_DEFINE_ID_TYPE
    #include <cstdint>
    #define CMX_TYPEID_DEFINE_ID_TYPE uintptr_t
#endif

namespace cmx
{

/**
 * @brief Generates a unique id for a type
 * 
 * @tparam T Type to query for unique ID
 * @tparam id_t type of unique ID 
 */
template<typename T, typename id_t = CMX_TYPEID_DEFINE_ID_TYPE>
struct typeinfo
{
    /**
     * @brief Returns a unique id for a specific type
     * 
     * @note The unique id is not deterministic. It is guaranteed that the id is consistent during the lifetime of
     *  the program during runtime. However, it is not guaranteed that the id is consistent at compile-time or
     *  in between two separate program executions. 
     * 
     * @return constexpr uintptr_t unique id associated to the type
     */
    static id_t unique_id()
    {
        return (id_t)(&unique_id);
    }
};

}

#endif // TYPEID_H
