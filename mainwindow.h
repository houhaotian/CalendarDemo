#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QCalendarWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void activeMemoDialog();

private:
    Ui::MainWindow *ui;
    QCalendarWidget *m_calendar;
};

#endif // MAINWINDOW_H
