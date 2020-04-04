#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "memodialog.h"
#include <QSettings>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_calendar = ui->calendarWidget;
    connect(m_calendar, &QCalendarWidget::activated, this, &MainWindow::activeMemoDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::activeMemoDialog()
{
    QSettings s(qApp->applicationDirPath() + "/cardemo.ini", QSettings::IniFormat);
    s.setIniCodec("UTF-8");
    QString date = m_calendar->selectedDate().toString("yyyy-MM-dd");
    QByteArray memos = s.value(date).toByteArray();

    qDebug()<<date<<memos;

    MemoDialog d(memos, this);
    if(d.exec()) {
        s.setValue(date, d.text());
        qDebug()<<date<<d.text()<<s.value(date);
    }
}
