#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <functional>
#include <iostream>
#include <QList>
#include <QDir>
#include <fstream>
#include <string>
#include "Markdown/ReportType.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    auto f_report = m_reportContext.newReport(markdown::ReportSystemType::kGNSS,markdown::ReportType::kGNSSPOSITION);
    auto outfile = QString("%1%2%3.md").arg(QDir::currentPath()).arg(QDir::separator()).arg(f_report->reportName());
    f_report->createMDFile(outfile.toStdWString());
    f_report->editTable();
    f_report->saveAndClose();
}
