#include "Markdown/HtmlTableBase.h"

namespace markdown {
HtmlTableBase::~HtmlTableBase()
{

}

HtmlTableBase::HtmlTableBase(std::wofstream *stream, const std::wstring &head, const std::wstring &tail):m_bMerge(false),m_rowSpan(0),m_colSpan(0),m_align(ALIGNMENT::LEFT)
{
    m_stream = stream;
    m_head = head;
    m_tail = tail;
}

void HtmlTableBase::setRowSpan(const unsigned int& rowSpan)
{
    m_rowSpan = rowSpan;
}

void HtmlTableBase::setColSpan(const unsigned int& colSpan)
{
    m_colSpan = colSpan;
}

void HtmlTableBase::setAlign(const ALIGNMENT &align)
{
    m_align = align;
}

unsigned int HtmlTableBase::rowSpan() const
{
    return m_rowSpan;
}

unsigned int HtmlTableBase::colSpan() const
{
    return m_colSpan;
}

bool HtmlTableBase::bMerge() const
{
    return m_bMerge;
}

void HtmlTableBase::setMerge()
{
    m_bMerge = true;
}
}

