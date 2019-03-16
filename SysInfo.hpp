#ifndef SYSINFO_HPP
#define SYSINFO_HPP


class SysInfo
{

public:
    static SysInfo& instance();

    SysInfo(const SysInfo& info) = delete;
    SysInfo& operator=(const SysInfo& info) = delete;

    virtual void init() = 0;
    virtual double memoryUsed() = 0;
    virtual double cpuLoadAverage() = 0;

    virtual ~SysInfo() = default;
protected:
    explicit SysInfo();

};

#endif // SYSINFO_HPP
