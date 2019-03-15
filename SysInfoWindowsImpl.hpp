#ifndef SYSINFOWINDOWSIMPL_HPP
#define SYSINFOWINDOWSIMPL_HPP

#include <cinttypes>

#include <windows.h>

#include "SysInfo.hpp"

class SysInfoWindowsImpl:public SysInfo
{
public:
    SysInfoWindowsImpl();
    void init() override;
    double memoryUsed() override;
    double cpuLoadAverage() override;

private:
    double cpuLoadAvarege(uint64_t idleTicks, uint64_t totalTicks);
    uint64_t fileTimeToUInt64(const FILETIME& fileTime) const;
private:
    double calculateCPULoadAverage;
    double m_prevCpuLoadAverage;
    uint64_t m_prevIdleTicks;
    uint64_t m_prevTotalTicks;
};

#endif // SYSINFOWINDOWSIMPL_HPP
