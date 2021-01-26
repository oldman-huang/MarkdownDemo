#include "Markdown/IReport.h"
#include <QDir>

namespace markdown {
markdown::IReport::IReport(const std::wstring &name)
{
    m_name = name;
}

std::wstring IReport::reportName() const
{
    return m_name;
}

void IReport::createMDFile(const std::wstring fileName)
{
    m_table = std::make_shared<markdown::HtmlTable>(&m_stream,m_name,L"");

    QFileInfo f_fileInfo(QString::fromStdWString(fileName));
    QDir f_path(f_fileInfo.path());
    if(f_path.exists(f_fileInfo.path())==false)
    {
       f_path.mkpath(f_fileInfo.path());
    }

    m_stream.imbue(std::locale("chs"));
    m_stream.open(fileName, std::ios::out);
}

void IReport::saveAndClose()
{
    m_table->autoMerge();
    m_table->toFile();
    m_stream.close();
}
}

