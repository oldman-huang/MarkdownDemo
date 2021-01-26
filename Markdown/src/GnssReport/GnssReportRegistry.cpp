#include "src/GnssReport/GnssReportRegistry.h"
#include "src/GnssReport/GnssPositionAccuracyReport.h"

namespace markdown {
namespace gnssreport{


GnssReportRegistry::GnssReportRegistry()
{
    //GNSS报表注册
    reportRegister<markdown::gnssreport::GnssPositionAccuracyReport>(markdown::ReportType::kGNSSPOSITION,std::wstring(L"GNSS定位精度测试"));
}

std::shared_ptr<IReport> GnssReportRegistry::getReport(const ReportType &type)
{
    if(m_report.contains(type))
    {
        return m_report[type];
    }else
    {
        return nullptr;
    }
}

ReportType GnssReportRegistry::reportType(const std::wstring &name) const
{
    return m_name.key(name);
}

std::wstring GnssReportRegistry::reportName(const ReportType &type) const
{
    return m_name[type];
}

void GnssReportRegistry::regist(const ReportType &type, const std::wstring& name, std::shared_ptr<IReport> report)
{
    m_report[type] = report;
    m_name[type] = name;
}

template<typename T>
void GnssReportRegistry::reportRegister(const ReportType &type, const std::wstring& name)
{
    regist(type,name,std::make_shared<T>(name));
}

}
}
