#include "Markdown/HtmlTableCell.h"
#include <stdlib.h>
#include <QFile>
namespace markdown {
HtmlTableCell::HtmlTableCell(std::wofstream *stream, const std::wstring &value, const ALIGNMENT &align):HtmlTableBase(stream,std::wstring(L"    <td>"),std::wstring(L"</td>"))
{
    m_value = value;
    m_align = align;
}

HtmlTableCell::~HtmlTableCell()
{

}

void HtmlTableCell::setValue(const std::wstring &value)
{
    m_value = value;
}

std::wstring HtmlTableCell::getValue()
{
    return m_value;
}

void HtmlTableCell::toFile()
{
    if(m_stream==nullptr)
        return;

    if(bMerge())
    {
        return;
    }
    
    if(rowSpan()>0)
    {
        m_head.insert(m_head.length()-1,std::wstring(L" rowspan=\"")+std::to_wstring(rowSpan())+std::wstring(L"\"")); //<td rowspan="8">
    }

    if(colSpan()>0)
    {
        m_head.insert(m_head.length()-1,std::wstring(L" colspan=\"")+std::to_wstring(colSpan())+std::wstring(L"\""));//<td colspan="2">
    }

    if(m_align==ALIGNMENT::RIGHT)
    {
        m_head.insert(m_head.length()-1,std::wstring(L" align=\"right\""));//<td align="right">
    }else if(m_align==ALIGNMENT::CENTER)
    {
        m_head.insert(m_head.length()-1,std::wstring(L" align=\"center\""));//<td align="center">
    }

    *m_stream<<m_head;
    if(m_value!=std::wstring(L""))
    {
        if((m_value.find(L".jpg")!=m_value.npos)||(m_value.find(L".bmp")!=m_value.npos)||(m_value.find(L".png")!=m_value.npos))
        {
            if(QFile::exists(QString::fromStdWString(m_value)))
            {
                *m_stream<<std::wstring(L"<img src=\"")<< m_value<<std::wstring(L"\" style=\"zoom:25%;\"/>");
            }
        }else
        {
            *m_stream<<m_value;
        }
    }
    *m_stream<<m_tail<<std::endl;
}
}
