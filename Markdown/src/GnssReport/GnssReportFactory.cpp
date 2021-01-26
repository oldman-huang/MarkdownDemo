#include "src/GnssReport/GnssReportFactory.h"

namespace markdown{
namespace gnssreport{
GnssReportFactory::GnssReportFactory(const ReportSystemType &reportSystem):m_reportSystem(ReportSystemType::kGNSS)
{
    m_reportSystem = reportSystem;
}

std::shared_ptr<IReport> GnssReportFactory::getReport(const markdown::ReportType &type)
{
   return m_registry.getReport(type);
}

ReportType GnssReportFactory::reportType(const std::wstring &name) const
{
    return m_registry.reportType(name);
}

std::wstring GnssReportFactory::reportName(const ReportType &type) const
{
    return m_registry.reportName(type);
}
}
}

