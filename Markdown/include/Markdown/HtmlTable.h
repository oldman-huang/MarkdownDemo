#ifndef MARKDOWN_HTML_TABLE_H_
#define MARKDOWN_HTML_TABLE_H_
#include "Markdown/Config.h"
#include "Markdown/HtmlTableCell.h"
#include <QList>
#include <QMap>
#include <memory>

namespace markdown {
class HtmlTable:public HtmlTableBase
{
public:
    HtmlTable() =default;
    ~HtmlTable();
    HtmlTable(std::wofstream *stream, const std::wstring caption=std::wstring(L""), const std::wstring bookmark=std::wstring(L""));

    void addCell(const std::pair<unsigned int,unsigned int>& position, const std::wstring& value=std::wstring(L""),const ALIGNMENT& align=ALIGNMENT::LEFT);
    void addRow(const QList<std::wstring>& list,const ALIGNMENT& align=ALIGNMENT::LEFT);
    void addColumn(const QList<std::wstring>& list,const ALIGNMENT& align=ALIGNMENT::LEFT);
    void addTable(const std::pair<unsigned int,unsigned int>& position, const std::shared_ptr<HtmlTable> table);
    void merge(const std::pair<unsigned int,unsigned int>& start,const std::pair<unsigned int,unsigned int>& stop);
    void setValue(const std::pair<unsigned int,unsigned int>& position, const std::wstring &value);

    void autoMerge();


    void setValue(const std::wstring &value) override;
    std::wstring getValue() override;
    void toFile() override;
private:
    //获取表格中的总行数
    unsigned int rows();
    //获取表格中的总列数
    unsigned int columns();

    std::wstring m_caption;
    std::wstring m_html;
    QMap<std::pair<unsigned int, unsigned int>,std::shared_ptr<HtmlTableBase>> m_table;
};
}


#endif // MARKDOWN_HTML_TABLE_H_
