#ifndef MARKDOWN_REPORT_TYPE_H_
#define MARKDOWN_REPORT_TYPE_H_
#include <QObject>
#include "Markdown/Config.h"

namespace markdown{
//报表系统类型
enum MARKDOWN_EXPORT ReportSystemType
{
    kNULL=0,
    kGNSS,//GNSS测试系统
    KSTAR,//对天可靠性系统
    kRFCHIP//射频芯片测试系统
};

//测试项目报表类型
enum MARKDOWN_EXPORT ReportType
{
    kGNSSPOSITION =0,
    KGNSSSPEED
};
}
#endif // MARKDOWN_REPORT_TYPE_H_
