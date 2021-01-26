#ifndef MARKDOWN_HTML_TABLE_CELL_H_
#define MARKDOWN_HTML_TABLE_CELL_H_
#include <string>
#include "Markdown/HtmlTableBase.h"

namespace markdown {
class HtmlTableCell:public HtmlTableBase
{
public:
    HtmlTableCell()=default;
    HtmlTableCell(std::wofstream *stream,const std::wstring &value=std::wstring(L""),const ALIGNMENT& align=ALIGNMENT::LEFT);
    ~HtmlTableCell();

    void setValue(const std::wstring &value) override;
    std::wstring getValue() override;
    void toFile() override;
private:
    std::wstring m_value;
};
}


#endif // MARKDOWN_HTML_TABLE_CELL_H_
