#ifndef MEMODIALOG_H
#define MEMODIALOG_H

#include <QDialog>

namespace Ui {
class MemoDialog;
}

class MemoDialog : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QByteArray TEXT READ text WRITE setText)

public:
    explicit MemoDialog(QWidget *parent = nullptr);
    MemoDialog(const QByteArray &t, QWidget *parent = nullptr);
    ~MemoDialog();

    QByteArray text();
    void setText(const QByteArray &s);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::MemoDialog *ui;
    QByteArray m_text;
};

#endif // MEMODIALOG_H
