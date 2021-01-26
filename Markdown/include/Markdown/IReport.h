#ifndef MARKDOWN_I_REPORT_H_
#define MARKDOWN_I_REPORT_H_
#include "Markdown/Config.h"
#include <string>
#include <iostream>
#include <memory>
#include "Markdown/HtmlTable.h"

namespace markdown {
class MARKDOWN_EXPORT IReport
{
public:
    IReport()=default;
    IReport(const std::wstring& name);
    virtual ~IReport()=default;

    IReport(const IReport&) = delete;
    const IReport& operator=(const IReport&) =delete;
    std::wstring reportName() const;
    void createMDFile(const std::wstring fileName);
    void saveAndClose();


    virtual void editTable()=0;
protected:
    std::wstring m_name;
    std::wofstream m_stream;
    std::shared_ptr<markdown::HtmlTable> m_table;
};
}


#endif // MARKDOWN_I_REPORT_H_
