#pragma once

namespace cmx
{

class RAII
{
public:
    using Startup_f = void(*)();
    using Cleanup_f = void(*)();

private:
    Startup_f startup;
    Cleanup_f cleanup;

public:
    RAII(Startup_f startup, Cleanup_f cleanup);

    ~RAII();
};

} // namespace cmx
