#include "Markdown/ReportContext.h"
namespace markdown {
ReportContext::ReportContext()
{

}

ReportContext::~ReportContext()
{

}

std::shared_ptr<IReport> ReportContext::newReport(const ReportSystemType &system, const ReportType &type)
{
    auto f_factory = m_factoryRegistry.getFactory(system);

    if(f_factory)
    {
        return f_factory->getReport(type);
    }

    return nullptr;
}
}

