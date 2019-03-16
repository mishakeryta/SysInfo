#include "SysInfo.hpp"

#include <QtGlobal>

#if defined(Q_OS_WIN)
    #include "SysInfoWindowsImpl.hpp"
#elif defined(Q_OS_LINUX)
//TODO
#endif



SysInfo &SysInfo::instance()
{
#if defined(Q_OS_WIN)
        static SysInfoWindowsImpl singleton;
#elif defined(Q_OS_LINUX)
        static_assert(true, "Linux SysInfoImpl is not implemented");
#endif

    return singleton;
}

SysInfo::SysInfo()
{
}
