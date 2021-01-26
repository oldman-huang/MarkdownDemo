#ifndef MARKDOWN_REPORT_FACTORY_REGISTRY_H_
#define MARKDOWN_REPORT_FACTORY_REGISTRY_H_
#include "Markdown/ReportType.h"
#include "Markdown/IReportFactory.h"
#include <memory>

namespace markdown{
class ReportFactoryRegistry
{
public:
    ReportFactoryRegistry();
    ReportFactoryRegistry(const ReportFactoryRegistry&)=delete;
    const ReportFactoryRegistry& operator=(const ReportFactoryRegistry&) =delete;

    std::shared_ptr<IReportFactory> getFactory(const ReportSystemType& reportSystem);
private:
    void regist(const ReportSystemType& reportSystem,std::shared_ptr<IReportFactory> factory);

    template<typename T>
    void reportSystemRegister(const markdown::ReportSystemType &reportSystem);
    QMap<ReportSystemType,std::shared_ptr<IReportFactory>> m_factory;
};
}


#endif // MARKDOWN_REPORT_FACTORY_REGISTRY_H_
