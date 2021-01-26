#ifndef MARKDOWN_GNSS_REPORT_GNSS_REPORT_REGISTRY_H_
#define MARKDOWN_GNSS_REPORT_GNSS_REPORT_REGISTRY_H_
#include "Markdown/ReportType.h"
#include "Markdown/IReport.h"
#include <QMap>
#include <memory>

namespace markdown {
namespace gnssreport{
class GnssReportRegistry
{
public:
    GnssReportRegistry();
    GnssReportRegistry(const GnssReportRegistry&)=delete;
    const GnssReportRegistry& operator=(const GnssReportRegistry&) =delete;

    std::shared_ptr<IReport> getReport(const ReportType& type);
    ReportType reportType(const std::wstring& name) const;
    std::wstring reportName(const ReportType& type) const;
private:
    template<typename T>
    void reportRegister(const ReportType& type,const std::wstring& name);

    void regist(const ReportType& type,const std::wstring& name,std::shared_ptr<IReport> report);
    QMap<markdown::ReportType,std::shared_ptr<markdown::IReport>> m_report;
    QMap<markdown::ReportType,std::wstring> m_name;

};
}
}
#endif // MARKDOWN_GNSS_REPORT_GNSS_REPORT_REGISTRY_H_
