#ifndef MARKDOWN_GNSS_REPORT_GNSS_POSITION_ACCURACY_REPORT_H_
#define MARKDOWN_GNSS_REPORT_GNSS_POSITION_ACCURACY_REPORT_H_
#include "Markdown/IReport.h"

namespace markdown {
namespace gnssreport{
class GnssPositionAccuracyReport:public IReport
{
public:
    GnssPositionAccuracyReport()=default;
    GnssPositionAccuracyReport(const std::wstring name);
    ~GnssPositionAccuracyReport();

    void editTable() override;
};
}
}
#endif // MARKDOWN_GNSS_REPORT_GNSS_POSITION_ACCURACY_REPORT_H_
