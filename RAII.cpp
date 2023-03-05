#include "RAII.hpp"

cmx::RAII::RAII(cmx::RAII::Startup_f startup, cmx::RAII::Cleanup_f cleanup)
    : startup(startup)
    , cleanup(cleanup)
{
    this->startup();
}

cmx::RAII::~RAII()
{
    cleanup();
}
