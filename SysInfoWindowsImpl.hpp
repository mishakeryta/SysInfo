#ifndef SYSINFOWINDOWSIMPL_HPP
#define SYSINFOWINDOWSIMPL_HPP

#include "SysInfo.hpp"

class SysInfoWindowsImpl:public SysInfo
{
public:
    SysInfoWindowsImpl();
    void init() override;
    double memoryUsed() override;
    double cpuLoadAverage() override;
};

#endif // SYSINFOWINDOWSIMPL_HPP
