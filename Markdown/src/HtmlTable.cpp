#include "Markdown/HtmlTable.h"
#include <QDebug>

namespace markdown {
HtmlTable::HtmlTable(std::wofstream *stream, const std::wstring caption, const std::wstring bookmark):HtmlTableBase(stream,std::wstring(L"<table>"),std::wstring(L"</table>"))
{
    m_caption = caption;
    if(bookmark!=std::wstring(L""))
    {
        m_head.insert(m_head.length()-1,std::wstring(L" bookmark=\"")+bookmark+std::wstring(L"\""));   //<table bookmark="我是书签">
    }
}

HtmlTable::~HtmlTable()
{

}

unsigned int HtmlTable::rows()
{
    unsigned int f_rows = 0;
    for(auto iter=m_table.begin();iter!=m_table.end();++iter)
    {
        auto rows=iter.key().first;
        if(rows>f_rows)
        {
            f_rows = rows;
        }
    }

    return f_rows;
}

unsigned int HtmlTable::columns()
{
    unsigned int f_columns = 0;
    for(auto iter=m_table.begin();iter!=m_table.end();++iter)
    {
        auto columns=iter.key().second;
        if(columns>f_columns)
        {
            f_columns = columns;
        }
    }
    return f_columns;
}



void HtmlTable::addCell(const std::pair<unsigned int, unsigned int> &position, const std::wstring &value, const ALIGNMENT &align)
{
    auto f_cell = std::make_shared<HtmlTableCell>(m_stream,value,align);
    m_table[position] = f_cell;
}

void HtmlTable::addRow(const QList<std::wstring> &list,const ALIGNMENT& align)
{
    auto f_rows =rows()+1;
    for(auto column =0;column<list.count();++column)
    {
        auto f_cell = std::make_shared<HtmlTableCell>(m_stream,list.at(column),align);
        std::pair<unsigned int, unsigned int> position(f_rows,column+1);
        m_table[position] = f_cell;
    }
}

void HtmlTable::addColumn(const QList<std::wstring> &list, const ALIGNMENT &align)
{
    auto f_columns =columns()+1;
    for(auto row =0;row<list.count();++row)
    {
        auto f_cell = std::make_shared<HtmlTableCell>(m_stream,list.at(row),align);
        std::pair<unsigned int, unsigned int> position(row+1,f_columns);
        m_table[position] = f_cell;
    }
}

void HtmlTable::addTable(const std::pair<unsigned int, unsigned int> &position, const std::shared_ptr<HtmlTable> table)
{
    m_table[position] = table;
}

void HtmlTable::merge(const std::pair<unsigned int,unsigned int>& start,const std::pair<unsigned int,unsigned int>& stop)
{
    auto f_rowspan = stop.first - start.first +1;
    auto f_colspan = stop.second - start.second +1;

    if(m_table[start]==nullptr)
    {
        //todo
        //std::wstring value = std::to_wstring(start.first)+L"_"+std::to_wstring(start.second);
        m_table[start] = std::make_shared<HtmlTableCell>(m_stream/*,value*/);
    }

    if(f_rowspan > 1)
    {
        m_table[start]->setRowSpan(f_rowspan);//行合并的话
    }

    if(f_colspan > 1)
    {
        m_table[start]->setColSpan(f_colspan);//列合并的话
    }

    //设置每个单元格的merge状态
    unsigned int row = start.first;
    unsigned int column = start.second;
    for(column =start.second+1;column<=stop.second;++column)
    {
        qDebug()<<QString("row:%1 column:%2").arg(row).arg(column);
        if(m_table[std::pair<unsigned int,unsigned int>(row,column)]==nullptr)
        {
            //todo
            //std::wstring value = std::to_wstring(row)+L"_"+std::to_wstring(column);
            m_table[std::pair<unsigned int,unsigned int>(row,column)] = std::make_shared<HtmlTableCell>(m_stream/*,value*/);
        }
        m_table[std::pair<unsigned int,unsigned int>(row,column)]->setMerge();
    }

    for(row =start.first+1;row<=stop.first;++row)
    {
        qDebug()<<QString("row:%1 column:%2").arg(row).arg(column);
        if(m_table[std::pair<unsigned int,unsigned int>(row,column)]==nullptr)
        {
            //todo
            //std::wstring value = std::to_wstring(row)+L"_"+std::to_wstring(column);
            m_table[std::pair<unsigned int,unsigned int>(row,column)] = std::make_shared<HtmlTableCell>(m_stream/*,value*/);
        }
        m_table[std::pair<unsigned int,unsigned int>(row,column)]->setMerge();
    }

    for(column =start.second+1;column<=stop.second;++column)
    {
        for(row =start.first+1;row<=stop.first;++row)
        {
            qDebug()<<QString("row:%1 column:%2").arg(row).arg(column);
            if(m_table[std::pair<unsigned int,unsigned int>(row,column)]==nullptr)
            {
                //todo
                //std::wstring value = std::to_wstring(row)+L"_"+std::to_wstring(column);
                m_table[std::pair<unsigned int,unsigned int>(row,column)] = std::make_shared<HtmlTableCell>(m_stream/*,value*/);
            }
            m_table[std::pair<unsigned int,unsigned int>(row,column)]->setMerge();
        }
    }
}

void HtmlTable::setValue(const std::wstring &value)
{

}

std::wstring HtmlTable::getValue()
{
    return std::wstring(L"");
}


void HtmlTable::setValue(const std::pair<unsigned int, unsigned int> &position, const std::wstring& value)
{
    if(m_table[position]!=nullptr)
    {
        m_table[position]->setValue(value);
    }
}

void HtmlTable::autoMerge()
{
    auto f_rows = rows();
    auto f_columns = columns();
    std::pair<unsigned int,unsigned int> f_position;
    for(unsigned int row=1;row<=f_rows;++row)
    {
        unsigned int f_columnIndex=1;
        for(unsigned int column =1;column<=f_columns;++column)
        {
            f_position =std::pair<unsigned int,unsigned int>(row,column);
            auto f_cell = m_table[f_position];
            if(f_cell==nullptr)
            {
                //todo
                //std::wstring value = std::to_wstring(row)+L"_"+std::to_wstring(column);
                m_table[f_position] = std::make_shared<HtmlTableCell>(m_stream/*,value*/);
            }else
            {
               if(f_cell->bMerge())//如果一行里面有合并项，则不处理本行
                {
                    f_columnIndex = f_columns;
                    break;
                }

                if(f_cell->getValue()!=std::wstring(L""))
                {
                    f_columnIndex=column;
                }
            }
        }

        if(f_columnIndex<f_columns)
        {
            merge(std::pair<unsigned int,unsigned int>(row,f_columnIndex),std::pair<unsigned int,unsigned int>(row,f_columns));
        }
    }
}

void HtmlTable::toFile()
{
    if(m_stream==nullptr)
        return;

    if(rows()==1 && columns()==1)
        return;

    (*m_stream)<<m_head<<std::endl;;

    if(m_caption!=std::wstring(L""))
    {
        *m_stream<<std::wstring(L"  <caption>")+m_caption+std::wstring(L"</caption>")<<std::endl;;
    }

    for(unsigned int row=1;row<=rows();++row)
    {
        *m_stream<<std::wstring(L"  <tr>")<<std::endl;;
        for(unsigned int column=1;column<=columns();++column)
        {
            std::pair<unsigned int, unsigned int> pos(row,column);
            if(m_table[pos]==nullptr)
            {
                //todo
                //std::wstring value = std::to_wstring(pos.first)+L"_"+std::to_wstring(pos.second);
                m_table[pos] = std::make_shared<HtmlTableCell>(m_stream/*,value*/);
            }

            m_table[pos]->toFile();
        }
        *m_stream<<std::wstring(L"  </tr>")<<std::endl;;
    }

    *m_stream<<m_tail<<std::endl;
}

}
