#pragma once
// optional library flags to pass to compiler

#ifndef CMX_NO_STL
    #include <cstdint>
#else
    #error "The library, at this time, requires the C++ Standard Template Library"
#endif

namespace cmx
{

} // namespace cmx
