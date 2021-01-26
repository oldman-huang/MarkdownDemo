#include "Markdown/ReportFactoryRegistry.h"
#include "src/GnssReport/GNSSReportFactory.h"

namespace markdown{
ReportFactoryRegistry::ReportFactoryRegistry()
{
    //报表类型注册
    reportSystemRegister<markdown::gnssreport::GnssReportFactory>(markdown::ReportSystemType::kGNSS);
}

std::shared_ptr<IReportFactory> ReportFactoryRegistry::getFactory(const ReportSystemType &reportSystem)
{
    if(m_factory.contains(reportSystem))
    {
        return m_factory[reportSystem];
    }else
    {
        return nullptr;
    }
}

void ReportFactoryRegistry::regist(const ReportSystemType &reportSystem, std::shared_ptr<IReportFactory> factory)
{
     m_factory[reportSystem] = factory;
}

template<typename T>
void ReportFactoryRegistry::reportSystemRegister(const markdown::ReportSystemType &reportSystem)
{
    regist(reportSystem,std::make_shared<T>(reportSystem));
}
}
