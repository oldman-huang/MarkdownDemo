#ifndef MARKDOWN_MARKDOWN_DOCUMENT_H_
#define MARKDOWN_MARKDOWN_DOCUMENT_H_
#include "Config.h"
#include <QMap>
#include "Markdown/HtmlTable.h"

namespace markdown {
class MarkdownDocument
{
public:
    MarkdownDocument();

private:
    QMap<std::wstring,std::shared_ptr<HtmlTable>> m_table;
};
}

#endif // MARKDOWN_MARKDOWN_DOCUMENT_H_
