#include "src/GnssReport/GnssPositionAccuracyReport.h"
#include <QDir>
namespace markdown {
namespace gnssreport{
GnssPositionAccuracyReport::GnssPositionAccuracyReport(const std::wstring name):IReport(name)
{

}

GnssPositionAccuracyReport::~GnssPositionAccuracyReport()
{

}

void GnssPositionAccuracyReport::editTable()
{
    m_table->addCell(std::pair<unsigned int,unsigned int>(1,1),std::wstring(L"测试基本信息"),markdown::ALIGNMENT::CENTER);
    m_table->addCell(std::pair<unsigned int,unsigned int>(2,1),std::wstring(L"测试时间"));
    m_table->addCell(std::pair<unsigned int,unsigned int>(2,2),std::wstring(L"2021-01-24 17:01:01"));
    m_table->addCell(std::pair<unsigned int,unsigned int>(2,3),std::wstring(L"设备厂商"));
    m_table->addCell(std::pair<unsigned int,unsigned int>(2,4),std::wstring(L"XXXXX信息有限公司"));
    m_table->addCell(std::pair<unsigned int,unsigned int>(3,1),std::wstring(L"型号"));
    m_table->addCell(std::pair<unsigned int,unsigned int>(3,2),std::wstring(L"MD-20211"));
    m_table->addCell(std::pair<unsigned int,unsigned int>(3,3),std::wstring(L"序列号"));
    m_table->addCell(std::pair<unsigned int,unsigned int>(3,4),std::wstring(L"310NKF92423"));

    m_table->addCell(std::pair<unsigned int,unsigned int>(4,1),std::wstring(L"测试条件"),markdown::ALIGNMENT::CENTER);
    QList<std::wstring> f_list ={L"温度",L"23℃",L"湿度",L"75%"};
    m_table->addRow(f_list);

    f_list.clear();
    f_list<<L"频点"<<L"X3"<<L"信号类型"<<L"C码";
    m_table->addRow(f_list);

    f_list.clear();
    f_list<<L"方位角"<<L"150°"<<L"俯仰角"<<L"90°";
    m_table->addRow(f_list);

    f_list.clear();
    f_list<<L"测试结果";
    m_table->addRow(f_list,markdown::ALIGNMENT::CENTER);

    f_list.clear();
    f_list<<L"水平精度"<<L"0.21"<<L"垂直精度"<<L"3.11";
    m_table->addRow(f_list);

    f_list.clear();
    f_list<<L"总体评价";
    m_table->addRow(f_list,markdown::ALIGNMENT::CENTER);

    f_list.clear();
    f_list<<L"指标"<<L"水平精度"<<L"10"<<L"垂直精度"<<L"10";
    m_table->addRow(f_list);

    f_list.clear();
    f_list<<L"评价结果"<<L"合格";
    m_table->addRow(f_list);

    f_list.clear();
    QString f_pic = QString("%1%2pic.jpg").arg(QDir::currentPath()).arg(QDir::separator());
    f_list<<f_pic.toStdWString();
    m_table->addRow(f_list,markdown::ALIGNMENT::CENTER);
}
}
}
