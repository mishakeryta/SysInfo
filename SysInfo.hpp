#ifndef SYSINFO_HPP
#define SYSINFO_HPP


class SysInfo
{
public:
    virtual ~SysInfo() = default;
    virtual void init() = 0;
    virtual double memoryUsed() = 0;
    virtual double cpuLoadAverage() = 0;
protected:
    SysInfo();
};

#endif // SYSINFO_HPP
