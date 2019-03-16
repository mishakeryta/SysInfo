#include "SysInfoWindowsImpl.hpp"

#include <windows.h>

SysInfoWindowsImpl::SysInfoWindowsImpl():
    SysInfo(),
    m_prevCpuLoadAverage(0),
    m_prevIdleTicks(0),
    m_prevTotalTicks(0)
{
}

void SysInfoWindowsImpl::init()
{
    cpuLoadAverage();
}

double SysInfoWindowsImpl::memoryUsed()
{
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&status);

    DWORDLONG memoryPhysicalUsed = status.ullTotalPhys - status.ullAvailPhys;
    return static_cast<double>(memoryPhysicalUsed)/static_cast<double>(status.ullTotalPhys);
}


double SysInfoWindowsImpl::cpuLoadAverage()
{
    FILETIME idleTime, kernelTime, userTime;
    if(GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
         double cpuLoad = calculateCpuLoadAverage(fileTimeToUInt64(idleTime),
                                                  fileTimeToUInt64(kernelTime) + fileTimeToUInt64(userTime));
         m_prevCpuLoadAverage = cpuLoad;
         return  cpuLoad;
    }
    //TODO: add logs about fail
    return  m_prevCpuLoadAverage;
}

double SysInfoWindowsImpl::calculateCpuLoadAverage(uint64_t idleTicks, uint64_t totalTicks)
{
    int64_t idleTicksSinceLastTime = static_cast<int64_t>(idleTicks) - static_cast<int64_t>(m_prevIdleTicks);
    int64_t totalTicksSinceLastTime = static_cast<int64_t>(totalTicks) - static_cast<int64_t>(m_prevTotalTicks);
    double cpuLoad = 0;
    if(totalTicksSinceLastTime > 0) {
        cpuLoad = 1 - static_cast<double>(idleTicksSinceLastTime) / totalTicksSinceLastTime;
    }
    else {
        cpuLoad = 1;
    }
    return  cpuLoad;
}


uint64_t SysInfoWindowsImpl::fileTimeToUInt64(const FILETIME &fileTime) const
{
    return (static_cast<uint64_t>(fileTime.dwHighDateTime) << 32) |
            static_cast<uint64_t>(fileTime.dwLowDateTime);
}

