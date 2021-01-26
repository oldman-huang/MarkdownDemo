#ifndef MARKDOWN_GNSS_REPORT_GNSS_REPORT_FACTORY_H_
#define MARKDOWN_GNSS_REPORT_GNSS_REPORT_FACTORY_H_
#include "Markdown/ReportType.h"
#include "Markdown/IReport.h"
#include "Markdown/IReportFactory.h"
#include "src/GnssReport/GnssReportRegistry.h"

namespace markdown {
namespace gnssreport{
class GnssReportFactory:public IReportFactory
{
public:
    GnssReportFactory(const ReportSystemType &reportSystem);
    GnssReportFactory(const GnssReportFactory&) = delete;
    const GnssReportFactory& operator=(const GnssReportFactory&) = delete;

    std::shared_ptr<IReport> getReport(const ReportType& type) override;

    ReportType reportType(const std::wstring& name) const;
    std::wstring reportName(const ReportType& type) const;
protected:
    GnssReportFactory()=default;

private:
    ReportSystemType m_reportSystem;
    GnssReportRegistry m_registry;
};
}
}


#endif // MARKDOWN_GNSS_REPORT_GNSS_REPORT_FACTORY_H_
