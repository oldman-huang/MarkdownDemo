#ifndef MARKDOWN_HTML_TABLE_BASE_H_
#define MARKDOWN_HTML_TABLE_BASE_H_
#include <fstream>
#include <string>

namespace markdown {
enum ALIGNMENT{
    LEFT,
    RIGHT,
    CENTER
};


class HtmlTableBase
{
public:
    HtmlTableBase()=default;
    virtual ~HtmlTableBase();
    HtmlTableBase(std::wofstream *stream,const std::wstring& head,const std::wstring& tail);

    virtual void setValue(const std::wstring &value)=0;
    virtual std::wstring getValue()=0;
    virtual void toFile()=0;

    void setMerge();
    void setRowSpan(const unsigned int& rowSpan);
    void setColSpan(const unsigned int& colSpan);
    void setAlign(const ALIGNMENT& align);
    unsigned int rowSpan() const;
    unsigned int colSpan() const;
    bool bMerge() const;
protected:
    std::wofstream* m_stream;
    std::wstring m_head;
    std::wstring m_tail;
    ALIGNMENT m_align;
private:
    unsigned int m_rowSpan;
    unsigned int m_colSpan;
    bool m_bMerge;
};
}


#endif // MARKDOWN_HTML_TABLE_BASE_H_
