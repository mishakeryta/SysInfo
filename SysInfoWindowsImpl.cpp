#include "SysInfoWindowsImpl.hpp"

#include <windows.h>

SysInfoWindowsImpl::SysInfoWindowsImpl():
    SysInfo()
{
}

void SysInfoWindowsImpl::init()
{
    //TODO
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
         //double cpuLoad = calculateCPULoadAverage(fileTimeToUInt64(idleTime), fileTimeToUInt64(kernelTime)+fileTimeToUInt64(userTime));
         //m_prevCpuLoadAvarage = cpuLoad;
        // return  cpuLoad;
    }
    //TODO: add logs about fail
    return  m_prevCpuLoadAverage;
}

double SysInfoWindowsImpl::cpuLoadAvarege(uint64_t idleTicks, uint64_t totalTicks)
{
    //TODO
    return 0;
}

uint64_t SysInfoWindowsImpl::fileTimeToUInt64(const FILETIME &fileTime) const
{
    //TODO
    return 0;
}

