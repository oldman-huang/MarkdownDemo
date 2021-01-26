#ifndef MARKDOWN_I_REPORT_FACTORY_H_
#define MARKDOWN_I_REPORT_FACTORY_H_
#include <memory>
#include <QMap>
#include "Markdown/ReportType.h"
#include "Markdown/IReport.h"

namespace markdown {
class IReportFactory
{
public:
    virtual ~IReportFactory() = default;
    IReportFactory(const IReportFactory&) = delete;
    const IReportFactory& operator=(const IReportFactory&)=delete;

    virtual std::shared_ptr<IReport> getReport(const ReportType& type)=0;
protected:
    IReportFactory()=default;
};
}


#endif // MARKDOWN_I_REPORT_FACTORY_H_
