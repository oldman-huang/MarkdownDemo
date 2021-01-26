#ifndef MARKDOWN_REPORT_CONTEXT_H_
#define MARKDOWN_REPORT_CONTEXT_H_
#include "Markdown/Config.h"
#include "Markdown/ReportType.h"
#include "Markdown/ReportFactoryRegistry.h"

namespace markdown {
class MARKDOWN_EXPORT ReportContext
{
public:
    ReportContext();
    ~ReportContext();

    std::shared_ptr<IReport> newReport(const ReportSystemType& system,const ReportType& type);
private:
    ReportFactoryRegistry m_factoryRegistry;
};
}


#endif // MARKDOWN_REPORT_CONTEXT_H_
